#ifndef __QUEUE_H__
#define __QUEUE_H__


typedef struct _node { 
  void* data; 
  struct _node *next;
} qNode; 

typedef struct _queue {
  qNode* head;
} queue;

queue* queue_create(void); 
int queueIsEmpty(queue*);
void* queue_front(queue*);
void queue_enqueue(queue*, void*);
void queue_dequeue(queue*);
void queue_print(queue*);
void queue_destroy(queue*);


#endif
