//Team Members:Girish Patni(Email:gpatni@asu.edu) Andre Baptiste(Email:abaptist@asu.edu)


#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

int array[3] ={0,0,0};

typedef struct semaphore_t {
     pthread_mutex_t mutex;
     pthread_cond_t cond;
     int count;
} semaphore_t;

void init_sem(semaphore_t *s, int i)
{   
    s->count = i;
    pthread_mutex_init(&(s->mutex), NULL);
    pthread_cond_init(&(s->cond), NULL);
}


void P(semaphore_t *sem)
{   
    pthread_mutex_lock (&(sem->mutex)); 
    sem->count--;
    if (sem->count < 0) 
	pthread_cond_wait(&(sem->cond), &(sem->mutex));
    pthread_mutex_unlock (&(sem->mutex)); 
}


void V(semaphore_t * sem)
{   
    pthread_mutex_lock (&(sem->mutex)); 
    sem->count++;
    if (sem->count <= 0) {
	pthread_cond_signal(&(sem->cond));
    }
    pthread_mutex_unlock (&(sem->mutex)); 
    pthread_yield();
}

int n_array[3] = {1, 1, 1};
int n = 0;
semaphore_t mutex;

void function_reader(void)
{
    while (1){
      if(n_array[0] == 1 && n_array[1] == 1 && n_array[2] == 1){
        P(&mutex);
	int i = 0;
	for(i = 0; i <= 2; i++){
	  printf("parent consuming child: %d having value: %d \n", i, array[i]);
	}
        sleep(1);
	V(&mutex);// let other processes use the mutex.
	int j = 0;
	for(j = 0; j <= 2; j++){
	  n_array[j]--;
	}
      }
    }
}    

void function_writer(void)
{
  int local_n = n;
  n++;
    while (1){
      if(n_array[local_n] == 0){
	P(&mutex);
	array[local_n]++;
        sleep(1);
	V(&mutex);// let other processes use the mutex.
	n_array[local_n]++;
      }
    }
}    


int main()
{
  int n0 = 0;
  int n1 = 1;
  int n2 = 2;
 
    init_sem(&mutex, 1);
    start_thread(function_reader, NULL);
    start_thread(function_writer, NULL);
    start_thread(function_writer, NULL);
    start_thread(function_writer, NULL);

    while(1) sleep(1);

    return 0;
}




