#include<stdio.h>
#include<stdlib.h>
#include<ucontext.h>
#include<string.h>
#include<unistd.h>
#include "q.h"
#define SIZE 8192

struct TCB_t *Curr_Thread = '\0';
    
static int count = 0;

void start_thread(void (*function)(void)){
    char *stack = (char *) malloc(SIZE*sizeof(char));
    struct TCB_t *tcb = (struct TCB_t *) malloc(sizeof(struct TCB_t));
    init_TCB(tcb, function, (void *) stack, SIZE);
    count++;
    AddQueue(Q,tcb);

}

void run() {
    Curr_Thread = DelQueue(Q);
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &(Curr_Thread->context));

}

void yield(){
    struct TCB_t *Prev_Thread;
    AddQueue(Q, Curr_Thread); 
    Prev_Thread = Curr_Thread;
    Curr_Thread = DelQueue(Q);
    swapcontext(&(Prev_Thread->context), &(Curr_Thread->context));

}
