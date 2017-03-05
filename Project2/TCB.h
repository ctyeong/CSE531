#include<stdio.h>
#include<stdlib.h>
#include<ucontext.h>
#include<string.h>
#include<unistd.h>


struct TCB_t {
      ucontext_t context;
      struct TCB_t *prev;
      struct TCB_t *next;
};

void init_TCB(struct TCB_t *tcb, void *function, void *stackP, int stack_size){
     memset(tcb, '\0', sizeof(struct TCB_t)); 
     getcontext(&tcb->context);
     tcb->context.uc_stack.ss_sp = stackP;
     tcb->context.uc_stack.ss_size  = (size_t) stack_size;
     makecontext(&tcb->context, function,0);
}