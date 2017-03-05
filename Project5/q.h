#include"tcb.h"
#include<stdio.h>
#include<stdlib.h>

struct item{
	struct item *next;
	struct item *prev;
	int val;
};

void InitQ(TCB_t ** head)
{
        *head=(TCB_t *)malloc(1*sizeof(TCB_t));
        (*head)->next = *head; 
	(*head)-> prev = *head;
}

void AddQueue( TCB_t * head,TCB_t * tcb)
{
	TCB_t *cur = head;
	while(cur->next!=head)
		cur=cur->next;
	cur -> next = tcb;
	tcb-> prev = cur;
	tcb->next = head;
	head-> prev = tcb;
}

TCB_t * DelQueue( TCB_t * head)
{
	TCB_t *cur = head-> next;
	TCB_t *cur_next = cur->next;
	head->next = cur_next;
	cur_next->prev=head;
	return cur;
}

struct item* NewItem(struct item *next, struct item *prev, int tid){
	struct item *temp;
	temp = (struct item *) malloc( sizeof(struct item) ); 
	temp->next = next;
	temp->prev = prev;
	temp->val = tid;
	return temp;
}
