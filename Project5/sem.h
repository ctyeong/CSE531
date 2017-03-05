#include <malloc.h> 
#include "threads.h"
typedef struct semap{
     TCB_t *queue;
     int count;
} semaphore_t;

extern TCB_t * Q;

void init_sem(semaphore_t *s, int i)
{  
	s->count = i;
	InitQ(&s->queue);
}

void P(semaphore_t *sem)
{    
	sem->count--;
	if (sem->count < 0) 
	{
		TCB_t *p=DelQueue(Q);
		AddQueue(sem->queue,p);
		swapcontext((p->context),(Q->next->context));
	}
}


void V(semaphore_t *sem)
{    
	sem->count++;
	if (sem->count <= 0)
	{
			TCB_t *temp = DelQueue(sem->queue);
			AddQueue(Q,temp);
	}
	yield();
}
