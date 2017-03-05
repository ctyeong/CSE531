/*
Girish Patni: gpatni@asu.edu
Andre Baptiste : abaptist@asu.edu
*/

#include "msgs.h"

#define SERVER_PORT 98
#define CLIENT_PORT 99

int tmp=0;
TCB_t * Q;

void client1()
{
char **client_list;
client_list = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_list[j]=(char *)malloc(20*sizeof(char));
client_list[0]="1aaaa";
client_list[1]="1bbbb";
client_list[2]="1cccc";
client_list[3]="1dddd";
client_list[4]="1eeee";

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
strcat(a,client_list[randnum]);
send(&p[SERVER_PORT], a,SERVER_PORT);  
sleep(1);
V(&p[SERVER_PORT].full);
}
}

void client2()
{
char **client_list;
client_list = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_list[j]=(char *)malloc(20*sizeof(char));
client_list[0]="2aaaa";
client_list[1]="2bbbb";
client_list[2]="2cccc";
client_list[3]="2dddd";
client_list[4]="2eeee";

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
strcat(a,client_list[randnum]);  
send(&p[SERVER_PORT], a,SERVER_PORT);
sleep(1);
V(&p[SERVER_PORT].full);
}
}

void client3()
{
while(1){
char **client_list;
client_list = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_list[j]=(char *)malloc(20*sizeof(char));
P(&p[CLIENT_PORT].full);
  if(tmp++%5==0){
  printf("\n\t\t\t\t\t\t\t\tInitiating 3rd client message receive\n");
  printf("\t\t\t\t\t\t\t\t **************************\n");
  for(j=0;j<5;j++)
	  receive(&p[CLIENT_PORT],client_list[j],CLIENT_PORT);
  printf("\n\t\t\t\t3rd client started receiving message\n");
  printf("\t\t*****************************************************\n");
  for(j=0;j<5;j++)
         printf("\n\t\t\t\t\t\t %s",client_list[j]);
	printf("\n");
  sleep(1);
}
V(&p[CLIENT_PORT].empty);
}
}

void client4()
{
while(1){
char **client_list;
client_list = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_list[j]=(char *)malloc(20*sizeof(char));
P(&p[CLIENT_PORT].full);
  if(tmp++%5==0){
  printf("\n\t\t\t\t\t\t\t\tInitiating 3rd client message receive\n");
  printf("\t\t\t\t\t\t\t\t **************************\n");
  for(j=0;j<5;j++)
	  receive(&p[CLIENT_PORT],client_list[j],CLIENT_PORT);
  printf("\n\t\t\t\t3rd client started receiving message\n");
  printf("\t\t*****************************************************\n");
  for(j=0;j<5;j++)
         printf("\n\t\t\t\t\t\t %s",client_list[j]);
	printf("\n");
  sleep(1);
}
V(&p[CLIENT_PORT].empty);
}
}

void client5()
{
while(1){
char **client_list;
client_list = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
        client_list[j]=(char *)malloc(20*sizeof(char));
P(&p[CLIENT_PORT].full);
  if(tmp++%5==0){
  printf("\n\t\t\t\t\t\t\t\tInitiating 3rd client message receive\n");
  printf("\t\t\t\t\t\t\t\t **************************\n");
  for(j=0;j<5;j++)
	  receive(&p[CLIENT_PORT],client_list[j],CLIENT_PORT);
  printf("\n\t\t\t\t3rd client started receiving message\n");
  printf("\t\t*****************************************************\n");
  for(j=0;j<5;j++)
         printf("\n\t\t\t\t\t\t %s",client_list[j]);
	printf("\n");
  sleep(1);
}
V(&p[CLIENT_PORT].empty);
}
}

void server()
{
printf("\t\tStarting  Server \n");
printf("\t************************\n");
char **server_table;
server_table = (char **) malloc(5*sizeof(char *));
int j=0;
for(j=0;j<10;j++)
	server_table[j]=(char *)malloc(20*sizeof(char));

server_table[0]="s01";
server_table[1]="s02";
server_table[2]="s03";
server_table[3]="s04";
server_table[4]="s05";

for(j=0;j<5;j++)
	printf("\t\t server[%d]:%s\n",j,server_table[j]);
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
  printf("\n\t\t Server Recieved message %s from Client: %d \n",msg,clientid);
  printf("\n*******Server Content********\n");
  printf("**********************************\n");
	int k=0;
  for(k=0;k<5;k++)
        printf("\t\t server[%d]:%s\n",k,server_table[k]);
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


int main()
{   
   InitQ(&Q);
   p[0].in=0; p[0].out=0;
   p[20].in=0; p[20].out=0;
   p[99].in=0; p[99].out=0;
    init_port();
	printf("\n\t\t first client created\n");
    start_thread(client1);
	printf("\n\t\t second client created\n");
    start_thread(client2);
	printf("\n\t\t third client created\n");
    start_thread(client3);
	printf("\n\t\t Server is created\n");
	printf("\n\t**********************************\n");
    start_thread(server);
	run();
	sleep(1);
    while (1) 
	sleep(1);
}
