#include"q.h"
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 8192

extern TCB_t * Q;
TCB_t *Curr_Thread = '\0';    
static int count = 0;

void start_thread(void (*function)(void))
{
    char *stack = (char *) malloc(SIZE*sizeof(char));
    TCB_t *tcb = (TCB_t *) malloc(sizeof(TCB_t));
    init_TCB(tcb, function, (void *) stack, SIZE);
    count++;
    AddQueue(Q,tcb);
}


void run()
{
    ucontext_t parent;     
    getcontext(&parent);   
    swapcontext(&parent, (Q->next->context));

}


void yield() 
{
	ucontext_t* parent;     
	parent = (ucontext_t *)malloc(sizeof(ucontext_t));
	getcontext(parent);
	Q->next->context = parent;
	if(Q->next->next !=Q && Q->next !=Q){
		TCB_t * cur = Q->next;
		while(cur->next != Q){
			cur = cur->next;
		}
		TCB_t * ret = DelQueue(Q);
		cur->next = ret;
		ret->prev = cur;
		ret->next = Q;
		Q->prev = ret;
	}
	swapcontext(parent, (Q->next->context));
}
