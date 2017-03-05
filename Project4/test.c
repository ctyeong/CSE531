#include "msgs.h"

#define SERVER_PORT 98
#define CLIENT_PORT 99
int temp=0;
TCB_t * Q;

void client1()
{

char **client_table;
client_table = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_table[j]=(char *)malloc(20*sizeof(char));

client_table[0]="abc123";
client_table[1]="def123";
client_table[2]="ghi123";
client_table[3]="jkl123";
client_table[4]="mno123";


while(1){
P(&p[SERVER_PORT].empty);
  char *a;
a=(char *)malloc(20*sizeof(char));

char *c = (char *)malloc(1*sizeof(char));
int randnum = rand()%5;
c[0] = (char) ( ((int) '0') + randnum );
strcpy(a, c);

char *d = (char *)malloc(1*sizeof(char));
d[0]=(char)(((int)'0')+1);

strcat(a, d);
strcat(a,client_table[randnum]);

  send(&p[SERVER_PORT], a,SERVER_PORT);
  sleep(1);
V(&p[SERVER_PORT].full);
}
}

void client2()
{

char **client_table;
client_table = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_table[j]=(char *)malloc(20*sizeof(char));

client_table[0]="abc456";
client_table[1]="def456";
client_table[2]="ghi456";
client_table[3]="jkl456";
client_table[4]="mno456";



while(1){
P(&p[SERVER_PORT].empty);
  char *a;
a=(char *)malloc(20*sizeof(char));

char *c = (char *)malloc(1*sizeof(char));
int randnum = rand()%5;
c[0] = (char) ( ((int) '0') + randnum );
strcpy(a, c);

char *d = (char *)malloc(1*sizeof(char));
d[0]=(char)(((int)'0')+2);

strcat(a, d);
strcat(a,client_table[randnum]);


  send(&p[SERVER_PORT], a,SERVER_PORT);
  sleep(1);
V(&p[SERVER_PORT].full);
}
}

void client3()
{
while(1){
char **client_table;
client_table = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_table[j]=(char *)malloc(20*sizeof(char));

P(&p[CLIENT_PORT].full);
  if(temp++%5==0){
  //char b[20];
  printf("\n\t\t\t\t\t\t\t\t\t\tClient 3 recieve initiated\n");
  printf("\t\t\t\t\t\t\t\t\t\t**************************\n");
  for(j=0;j<5;j++)
	  receive(&p[CLIENT_PORT],client_table[j],CLIENT_PORT);
  printf("\n\t\t\t\t\t\t\t\t\t\tClient 3 recieving\n");
  printf("\t\t\t\t\t\t\t\t\t\t*******************\n");
  for(j=0;j<5;j++)
         printf("\n\t\t\t\t\t\t\t\t\t\t%s",client_table[j]);
	printf("\n");
  sleep(1);
}
V(&p[CLIENT_PORT].empty);
}
}

void server()
{
printf("Creating Server Table\n");
printf("======================\n");
char **server_table;
server_table = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
	server_table[j]=(char *)malloc(20*sizeof(char));

server_table[0]="abc";
server_table[1]="def";
server_table[2]="ghi";
server_table[3]="jkl";
server_table[4]="mno";

for(j=0;j<5;j++)
	printf("%d:%s\n",j,server_table[j]);
printf("\n");


while(1){
P(&p[SERVER_PORT].full);
  char a[20],ch;
char *msg;
msg=(char*)malloc(20*sizeof(char));
  int i=2;
j=0;
  receive(&p[SERVER_PORT],a,SERVER_PORT);
  char c=a[0];
int ind = c-'0';

 c = a[1];
int clientid = c-'0';

  while((ch=a[i++])!='\0')
   msg[j++]=ch;

  server_table[ind]=msg;
  printf("\nServer Recieved modification from Client %d message: %s index %d\n",clientid,msg,ind);
  printf("====================================================================\n");
	int k=0;
  for(k=0;k<5;k++)
        printf("%d:%s\n",k,server_table[k]);
  printf("\n");
  sleep(1);
V(&p[SERVER_PORT].empty);
P(&p[CLIENT_PORT].empty);

  int j=0;
  for(j=0;j<5;j++)
	send(&p[CLIENT_PORT], server_table[j],CLIENT_PORT);
  sleep(1);
V(&p[CLIENT_PORT].full);


}
}


//-------------------------------------------------------

int main()
{   //int a[] = {0,1,2,3,4};
	InitQ(&Q);
   p[0].in=0; p[0].out=0;
   p[20].in=0; p[20].out=0;
   p[99].in=0; p[99].out=0;
    init_port();
	printf("\n\t\t\t\t\t\tCreating a client1");
    start_thread(client1);
	printf("\n\t\t\t\t\t\tCreating a client2");
    start_thread(client2);
	printf("\n\t\t\t\t\t\tCreating a client3");
    start_thread(client3);
	printf("\n\t\t\t\t\t\tCreating a server");
	printf("\n\t\t\t\t\t\t*******************\n");
    start_thread(server);
	run();
    while (1) sleep(1);
} 
