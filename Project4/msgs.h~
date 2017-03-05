#include "sem.h"

typedef struct port 
{
	char **msgs;
	int in, out;
	semaphore_t mutex, full, empty;
}PORT;

PORT p[100];


void init_port() 
{
	printf("\n\t\t\t\t\t\tInitialize Ports\n");
	printf("\t\t\t\t\t\t*******************\n");
	int i=0;
	for(i=0;i<100;i++)
	{
		p[i].msgs=(char **) malloc(10*sizeof(char *));
		int j=0;
		for(j=0;j<10;j++)
		    p[i].msgs[j]=(char *) malloc(20*sizeof(char));
		init_sem(&p[i].full,0);
		init_sem(&p[i].empty,10);
		init_sem(&p[i].mutex,1);
	}
}
	

void send(PORT *p, char *msg,int portnum)
{
//    P(&p->empty);
    P(&p->mutex);
	strcpy(p->msgs[p->in],msg); 
  //	printf("Message sent to port %d at index: %d\n",portnum,p->in);
	p->in = ((p->in)+1)%10;
    V(&p->mutex);
 //   V(&p->full);
}

void receive(PORT *p, char *msg,int portnum)
{
  // P(&p->full);
    P(&p->mutex);
	strcpy(msg,p->msgs[p->out]);	
  	//printf("Message read from port %d at index: %d\n",portnum,p->out);
  	p->out = ((p->out)+1)%10;
    V(&p->mutex);
   // V(&p->empty);
}
