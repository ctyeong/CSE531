/*
Girish Patni: gpatni@asu.edu
Andre Baptiste : abaptist@asu.edu
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sem.h"

TCB_t * Q;

int rwc = 0 , wwc = 0 , rc = 0 , wc = 0, global_ID = 0;

sem_t r_sem,w_sem,mutex;

void reader_entry(int ID)
{
	printf("\t\t\t\t[reader: #%d] Trying to read\n",ID);
	P(&mutex);
	if(wwc > 0 || wc > 0)
	{
		printf("\t\t\t\t[reader: #%d] waiting for writer to finish\n", ID);
		rwc++;
		V(&mutex);
		P(&r_sem);
		rwc--;
	}
	rc++;
	if( rwc > 0 )
		V(&r_sem);
	else
		V(&mutex);
}

void reader_exit(int ID)
{
	P(&mutex);
	rc--;
	if(rc == 0 && wwc > 0 )
		V(&w_sem);
	else
		V(&mutex);	
}

void writer_entry(int ID)
{
	printf("[writer: #%d] trying to write\n",ID);
	P(&mutex);
	if(rc > 0 || wc > 0 )
	{
		printf("[writer: #%d] Waiting\n", ID);
		wwc++;
		V(&mutex);
		P(&w_sem);
		wwc--;
	}
	wwc++;
	V(&mutex);
}

void writer_exit(int ID)
{
	P(&mutex);
	wc--;
	if(rwc > 0)
		V(&r_sem);
	else if( wwc > 0 )
		V(&w_sem);
	else
		V(&mutex);
}

void reader()
{
	int ID;
	P(&mutex);
	ID = global_ID++;
	V(&mutex);
	while(1)
	{
		reader_entry(ID);
		printf("\t\t\t\t[reader: #%d] Reading\n",ID);
		sleep(1);
		reader_exit(ID);
	};
}

void writer()
{
	int ID;
	P(&mutex);
	ID = global_ID++;
	V(&mutex);
	while(1)
	{
		writer_entry(ID);
		printf("[writer: #%d] Writing\n ",ID);
		sleep(1);
		writer_exit(ID);
	};
}
int main()
{
	InitQ(&Q);
	init_sem(&mutex, 1);
	init_sem(&r_sem, 0);
	init_sem(&w_sem, 0);	
	start_thread(reader);
	start_thread(reader);
	start_thread(reader);
	start_thread(writer);
	start_thread(writer);		
	run();
}
