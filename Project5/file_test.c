#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define filesize 1025
#define filelength 15

void client1(char *fname)
{
char buffer[filesize];
int req, res, n;
req = open("req.fifo", O_WRONLY);
res = open("res.fifo", O_RDONLY);
if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
}
write(req, fname, sizeof(fname));
printf("Received response\n");
while((n = read(res, buffer, sizeof(buffer)))>0) {
    write(1, buffer, n);
}
close(req);
close(res);
char **client_list;
client_list = (char **) malloc(sizeof(char *));
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


FILE * file_open(char *x)
{
	FILE *fp = fopen(x, "rb");
	if(!fp) {
		perror("File does not exists");
		// Close the file
		fclose(fp);
		exit(1);
	}
	return fp;
}	
//Calculate size of file  
int file_size(FILE *fp)
{
	int sz;
	fseek(fp, 0L, SEEK_END);
	sz = ftell(fp);
	printf("the size of file is %d\n",sz);
	return sz;
}



void server(char *[]files){	
	char fname[filelength], buffer[filesize];
    int req, res, n, file;
    mkfifo("req.fifo", 0777);
    mkfifo("res.fifo", 0777);
    printf("Waiting for request...\n");
    req = open("req.fifo", O_RDONLY);
    res = open("res.fifo", O_WRONLY);
    read(req, fname, sizeof(fname));
    printf("Received request for %s\n", fname);
    file = open(fname, O_RDONLY);
    if (file < 0)
        write(res, "File not found\n", 15);
    else {
        while((n = read(file, buffer, sizeof(buffer))) > 0) {
            write(res, buffer, n);
        }
    }
    close(req);
    close(res);
    unlink("req.fifo");
    unlink("res.fifo");
    return 0;
}

void client1(char * fname){
    char fname[filelength], buffer[filesize];
    int req, res, n;
    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);
    if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
    }
    write(req, fname, sizeof(fname));
    printf("Received response\n");
    while((n = read(res, buffer, sizeof(buffer)))>0) {
        write(1, buffer, n);
    }
    close(req);
    close(res);
    return 0;
}
void client2(char * fname){
    char fname[filelength], buffer[filesize];
    int req, res, n;
    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);
    if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
    }
    printf("Enter filename to request:\n");
    scanf("%s", fname);
    write(req, fname, sizeof(fname));
    printf("Received response\n");
    while((n = read(res, buffer, sizeof(buffer)))>0) {
        write(1, buffer, n);
    }
    close(req);
    close(res);
    return 0;
}
void client3(char * fname){
    char fname[filelength], buffer[filesize];
    int req, res, n;
    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);
    if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
    }
    printf("Enter filename to request:\n");
    scanf("%s", fname);
    write(req, fname, sizeof(fname));
    printf("Received response\n");
    while((n = read(res, buffer, sizeof(buffer)))>0) {
        write(1, buffer, n);
    }
    close(req);
    close(res);
    return 0;
}
void client4(char * fname){
    char fname[filelength], buffer[filesize];
    int req, res, n;
    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);
    if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
    }
    printf("Enter filename to request:\n");
    scanf("%s", fname);
    write(req, fname, sizeof(fname));
    printf("Received response\n");
    while((n = read(res, buffer, sizeof(buffer)))>0) {
        write(1, buffer, n);
    }
    close(req);
    close(res);
    return 0;
}
void client5(char * fname){
    char fname[filelength], buffer[filesize];
    int req, res, n;
    req = open("req.fifo", O_WRONLY);
    res = open("res.fifo", O_RDONLY);
    if(req < 0 || res < 0) {
        printf("Please Start the server first\n");
        exit(-1);
    }
    printf("Enter filename to request:\n");
    scanf("%s", fname);
    write(req, fname, sizeof(fname));
    printf("Received response\n");
    while((n = read(res, buffer, sizeof(buffer)))>0) {
        write(1, buffer, n);
    }
    close(req);
    close(res);
    return 0;
}

int main(int argc , char *argv[])
{
    if(argc < 3)
    {
        printf("Invalid Command Format!\n");
        printf("Command type(c - client or s-server) port(such as 9669)\n");
        exit(0);
    }

    mode = (strcmp(argv[1],"c") == 0)? 1 : 0 ;
    port  = atoi(argv[2]);
    if(mode ==  SERVER)
	{
		run_server_part();
	}
    else if(mode == CLIENT)
	{
		run_client_part();
	}
    return 0;
}