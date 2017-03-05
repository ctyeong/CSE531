#include"TCB.h"
#include<stdio.h>
#include<stdlib.h>
struct item{
	struct item *next;
	struct item *prev;
	int val;
};
struct queue{
  struct TCB_t *head;
};
struct queue *Q;

int isEmpty(struct queue *Q){
if(Q->head==NULL)
  return 1;
return 0;
}

void AddQueue(struct queue *Q, struct TCB_t *tcb) {
   if(isEmpty(Q)) {
       Q->head = tcb;
       Q->head->next = Q->head;
       Q->head->prev = Q->head;
   } else {
       tcb->prev = Q->head->prev;
       tcb->next = Q->head;
       Q->head->prev->next = tcb; 
       Q->head->prev = tcb;
   }
}

struct TCB_t* DelQueue(struct queue *Q) {
   struct TCB_t *temp;
   if(isEmpty(Q))
      return NULL;
   else {
      temp = Q->head;
      if(Q->head->next == Q->head)
         Q->head = NULL;
      else {
      Q->head = Q->head->next;
      Q->head->prev = temp->prev;
      temp->prev->next = Q->head;
      }
      return temp;
   }
}

struct queue* newQueue(struct queue *Q) {
   Q = (struct queue *)malloc(sizeof(struct queue));
   Q->head = NULL;
   return Q;
}

struct item* NewItem(struct item *next, struct item *prev, int tid){
	struct item *temp;
	temp = (struct item *) malloc( sizeof(struct item) ); 
	temp->next = next;
	temp->prev = prev;
	temp->val = tid;
	return temp;
}

