  1: /* Copyright (C) 1991,1992,1996,1997,1999,2004 Free Software Foundation, Inc.
  2:    This file is part of the GNU C Library.
  3:    Written by Douglas C. Schmidt (schmidt@ics.uci.edu).
  4: 
  5:    The GNU C Library is free software; you can redistribute it and/or
  6:    modify it under the terms of the GNU Lesser General Public
  7:    License as published by the Free Software Foundation; either
  8:    version 2.1 of the License, or (at your option) any later version.
  9: 
 10:    The GNU C Library is distributed in the hope that it will be useful,
 11:    but WITHOUT ANY WARRANTY; without even the implied warranty of
 12:    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 13:    Lesser General Public License for more details.
 14: 
 15:    You should have received a copy of the GNU Lesser General Public
 16:    License along with the GNU C Library; if not, write to the Free
 17:    Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 18:    02111-1307 USA.  */
 19: 
 20: /* If you consider tuning this algorithm, you should consult first:
 21:    Engineering a sort function; Jon Bentley and M. Douglas McIlroy;
 22:    Software - Practice and Experience; Vol. 23 (11), 1249-1265, 1993.  */
 23: 
 24: #include <alloca.h>
 25: #include <limits.h>
 26: #include <stdlib.h>
 27: #include <string.h>
 28: 
 29: /* Byte-wise swap two items of size SIZE. */
 30: #define SWAP(a, b, size)                                                      \
 31:   do                                                                              \
 32:     {                                                                              \
 33:       register size_t __size = (size);                                              \
 34:       register char *__a = (a), *__b = (b);                                      \
 35:       do                                                                      \
 36:         {                                                                      \
 37:           char __tmp = *__a;                                                      \
 38:           *__a++ = *__b;                                                      \
 39:           *__b++ = __tmp;                                                      \
 40:         } while (--__size > 0);                                                      \
 41:     } while (0)
 42: 
 43: /* Discontinue quicksort algorithm when partition gets below this size.
 44:    This particular magic number was chosen to work best on a Sun 4/260. */
 45: #define MAX_THRESH 4
 46: 
 47: /* Stack node declarations used to store unfulfilled partition obligations. */
 48: typedef struct
 49:   {
 50:     char *lo;
 51:     char *hi;
 52:   } stack_node;
 53: 
 54: /* The next 4 #defines implement a very fast in-line stack abstraction. */
 55: /* The stack needs log (total_elements) entries (we could even subtract
 56:    log(MAX_THRESH)).  Since total_elements has type size_t, we get as
 57:    upper bound for log (total_elements):
 58:    bits per byte (CHAR_BIT) * sizeof(size_t).  */
 59: #define STACK_SIZE        (CHAR_BIT * sizeof(size_t))
 60: #define PUSH(low, high)        ((void) ((top->lo = (low)), (top->hi = (high)), ++top))
 61: #define        POP(low, high)        ((void) (--top, (low = top->lo), (high = top->hi)))
 62: #define        STACK_NOT_EMPTY        (stack < top)
 63: 
 64: 
 65: /* Order size using quicksort.  This implementation incorporates
 66:    four optimizations discussed in Sedgewick:
 67: 
 68:    1. Non-recursive, using an explicit stack of pointer that store the
 69:       next array partition to sort.  To save time, this maximum amount
 70:       of space required to store an array of SIZE_MAX is allocated on the
 71:       stack.  Assuming a 32-bit (64 bit) integer for size_t, this needs
 72:       only 32 * sizeof(stack_node) == 256 bytes (for 64 bit: 1024 bytes).
 73:       Pretty cheap, actually.
 74: 
 75:    2. Chose the pivot element using a median-of-three decision tree.
 76:       This reduces the probability of selecting a bad pivot value and
 77:       eliminates certain extraneous comparisons.
 78: 
 79:    3. Only quicksorts TOTAL_ELEMS / MAX_THRESH partitions, leaving
 80:       insertion sort to order the MAX_THRESH items within each partition.
 81:       This is a big win, since insertion sort is faster for small, mostly
 82:       sorted array segments.
 83: 
 84:    4. The larger of the two sub-partitions is always pushed onto the
 85:       stack first, with the algorithm then concentrating on the
 86:       smaller partition.  This *guarantees* no more than log (total_elems)
 87:       stack size is needed (actually O(1) in this case)!  */
 88: 
 89: void
 90: _quicksort (void *const pbase, size_t total_elems, size_t size,
 91:             __compar_fn_t cmp)
 92: {
 93:   register char *base_ptr = (char *) pbase;
 94: 
 95:   const size_t max_thresh = MAX_THRESH * size;
 96: 
 97:   if (total_elems == 0)
 98:     /* Avoid lossage with unsigned arithmetic below.  */
 99:     return;
100: 
101:   if (total_elems > MAX_THRESH)
102:     {
103:       char *lo = base_ptr;
104:       char *hi = &lo[size * (total_elems - 1)];
105:       stack_node stack[STACK_SIZE];
106:       stack_node *top = stack;
107: 
108:       PUSH (NULL, NULL);
109: 
110:       while (STACK_NOT_EMPTY)
111:         {
112:           char *left_ptr;
113:           char *right_ptr;
114: 
115:           /* Select median value from among LO, MID, and HI. Rearrange
116:              LO and HI so the three values are sorted. This lowers the
117:              probability of picking a pathological pivot value and
118:              skips a comparison for both the LEFT_PTR and RIGHT_PTR in
119:              the while loops. */
120: 
121:           char *mid = lo + size * ((hi - lo) / size >> 1);
122: 
123:           if ((*cmp) ((void *) mid, (void *) lo) < 0)
124:             SWAP (mid, lo, size);
125:           if ((*cmp) ((void *) hi, (void *) mid) < 0)
126:             SWAP (mid, hi, size);
127:           else
128:             goto jump_over;
129:           if ((*cmp) ((void *) mid, (void *) lo) < 0)
130:             SWAP (mid, lo, size);
131:         jump_over:;
132: 
133:           left_ptr  = lo + size;
134:           right_ptr = hi - size;
135: 
136:           /* Here's the famous ``collapse the walls'' section of quicksort.
137:              Gotta like those tight inner loops!  They are the main reason
138:              that this algorithm runs much faster than others. */
139:           do
140:             {
141:               while ((*cmp) ((void *) left_ptr, (void *) mid) < 0)
142:                 left_ptr += size;
143: 
144:               while ((*cmp) ((void *) mid, (void *) right_ptr) < 0)
145:                 right_ptr -= size;
146: 
147:               if (left_ptr < right_ptr)
148:                 {
149:                   SWAP (left_ptr, right_ptr, size);
150:                   if (mid == left_ptr)
151:                     mid = right_ptr;
152:                   else if (mid == right_ptr)
153:                     mid = left_ptr;
154:                   left_ptr += size;
155:                   right_ptr -= size;
156:                 }
157:               else if (left_ptr == right_ptr)
158:                 {
159:                   left_ptr += size;
160:                   right_ptr -= size;
161:                   break;
162:                 }
163:             }
164:           while (left_ptr <= right_ptr);
165: 
166:           /* Set up pointers for next iteration.  First determine whether
167:              left and right partitions are below the threshold size.  If so,
168:              ignore one or both.  Otherwise, push the larger partition's
169:              bounds on the stack and continue sorting the smaller one. */
170: 
171:           if ((size_t) (right_ptr - lo) <= max_thresh)
172:             {
173:               if ((size_t) (hi - left_ptr) <= max_thresh)
174:                 /* Ignore both small partitions. */
175:                 POP (lo, hi);
176:               else
177:                 /* Ignore small left partition. */
178:                 lo = left_ptr;
179:             }
180:           else if ((size_t) (hi - left_ptr) <= max_thresh)
181:             /* Ignore small right partition. */
182:             hi = right_ptr;
183:           else if ((right_ptr - lo) > (hi - left_ptr))
184:             {
185:               /* Push larger left partition indices. */
186:               PUSH (lo, right_ptr);
187:               lo = left_ptr;
188:             }
189:           else
190:             {
191:               /* Push larger right partition indices. */
192:               PUSH (left_ptr, hi);
193:               hi = right_ptr;
194:             }
195:         }
196:     }
197: 
198:   /* Once the BASE_PTR array is partially sorted by quicksort the rest
199:      is completely sorted using insertion sort, since this is efficient
200:      for partitions below MAX_THRESH size. BASE_PTR points to the beginning
201:      of the array to sort, and END_PTR points at the very last element in
202:      the array (*not* one beyond it!). */
203: 
204: #define min(x, y) ((x) < (y) ? (x) : (y))
205: 
206:   {
207:     char *const end_ptr = &base_ptr[size * (total_elems - 1)];
208:     char *tmp_ptr = base_ptr;
209:     char *thresh = min(end_ptr, base_ptr + max_thresh);
210:     register char *run_ptr;
211: 
212:     /* Find smallest element in first threshold and place it at the
213:        array's beginning.  This is the smallest array element,
214:        and the operation speeds up insertion sort's inner loop. */
215: 
216:     for (run_ptr = tmp_ptr + size; run_ptr <= thresh; run_ptr += size)
217:       if ((*cmp) ((void *) run_ptr, (void *) tmp_ptr) < 0)
218:         tmp_ptr = run_ptr;
219: 
220:     if (tmp_ptr != base_ptr)
221:       SWAP (tmp_ptr, base_ptr, size);
222: 
223:     /* Insertion sort, running from left-hand-side up to right-hand-side.  */
224: 
225:     run_ptr = base_ptr + size;
226:     while ((run_ptr += size) <= end_ptr)
227:       {
228:         tmp_ptr = run_ptr - size;
229:         while ((*cmp) ((void *) run_ptr, (void *) tmp_ptr) < 0)
230:           tmp_ptr -= size;
231: 
232:         tmp_ptr += size;
233:         if (tmp_ptr != run_ptr)
234:           {
235:             char *trav;
236: 
237:             trav = run_ptr + size;
238:             while (--trav >= run_ptr)
239:               {
240:                 char c = *trav;
241:                 char *hi, *lo;
242: 
243:                 for (hi = lo = trav; (lo -= size) >= tmp_ptr; hi = lo)
244:                   *hi = *lo;
245:                 *hi = c;
246:               }
247:           }
248:       }
249:   }
250: }
