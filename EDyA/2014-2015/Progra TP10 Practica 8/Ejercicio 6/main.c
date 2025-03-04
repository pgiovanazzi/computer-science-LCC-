#include <stdio.h>
#include <stdlib.h>

void combine(int data1[], int sz1,
			 int data2[], int sz2,
			 int r[]) {
	int i = 0, j = 0, k;

	for (k = 0; k < sz1 + sz2; k++) {
		if (i < sz1 && j < sz2 && data1[i] >= data2[j] || i < sz1 && j >= sz2)
			r[k] = data1[i++];
		else if (i < sz1 && j < sz2 && data2[j] >= data1[i] || j < sz2 && i >= sz1)
			r[k] = data2[j++];
	}
}

int *solve(int data[], int sz) {
	int *r = malloc(sizeof(int) * sz);
	int *h = malloc(sizeof(int) * 2);
	int mid = sz/2;
	int *sub1, *sub2;

	if (sz == 1) {
		r[0] = data[0];
		return r;
	}

	sub1 = solve(data, mid);
	sub2 = solve(data + mid, sz - mid);

	combine(sub1, mid, sub2, sz - mid, r);

	h[0] = r[0];
	h[1] = r[1];

	free(r);
	free(sub1);
	free(sub2);

	return h;
}

int main(void) {
	int i;
	int lst[] = { 3, 5, 1, 4, 2 };
	int *r = solve(lst, 5);

	printf("%d\t%d\t", r[0], r[1]);
	puts("");
	
	return 0;
}
