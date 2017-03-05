#include<ucontext.h>
#include<stdio.h>
#include<string.h>
struct TCB{
         struct TCB *next;
         struct TCB *prev;
        ucontext_t context;
};

typedef struct TCB TCB_t;

void init_TCB (struct TCB *tcb, void *function, void *stackP, int stack_size)
{
	memset(tcb,'\0',sizeof(TCB_t));
	getcontext(&tcb->context);
	tcb->context.uc_stack.ss_sp = stackP;
	tcb->context.uc_stack.ss_size = (size_t) stack_size;
	makecontext(&tcb->context, function, 0);
}
