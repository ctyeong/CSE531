/*
Girish Patni: gpatni@asu.edu
Andre Baptiste : abaptist@asu.edu
*/
#include<stdio.h>
#include<stdlib.h>
#include<ucontext.h>
#include<string.h>
#include<unistd.h>
#include "threads.h"

int global=0;

void functionA()
{
   int local = 0;

    while (1){
        printf("FunctionA             global:= %d local:= %d\n", global, local);
        sleep(1);
        global++; 
        local ++;
        yield();
        printf("FunctionA incremented global:= %d local:= %d\n", global, local);        
    }
}  

void functionB()
{
   int local = 0;

    while (1){
        printf("FunctionB             global:= %d local:= %d\n", global, local);
        sleep(1);
        global++; 
        local ++;
        yield();
        printf("FunctionB incremented global:= %d local:= %d\n", global, local);
        
    }
}    

void functionC()
{
   int local = 0;

    while (1){
        printf("FunctionC             global:= %d local:= %d\n", global, local);
        sleep(1);
        global++; 
        local ++;
        yield();
        printf("FunctionC incremented global:= %d local:= %d\n", global, local);      
    }
}   


int main()
{  
    Q=newQueue(Q);
    start_thread(functionA);
    start_thread(functionB);
    start_thread(functionC);
    run();
    return 1;
}
