#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAXLEN 500
#define BUFFLEN 1024
#define MAX_CLIENTS 10

ssize_t Readline(int sockd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char    c, *buffer;

    buffer = vptr;

    for ( n = 1; n < maxlen; n++ ) {	
	if ( (rc = read(sockd, &c, 1)) == 1 ) {
	    *buffer++ = c;
	    if ( c == '\n' )
		break;
	}
	else if ( rc == 0 ) {
	    if ( n == 1 )
		return 0;
	    else
		break;
	}
	else {
	    if ( errno == EINTR )
		continue;
	    return -1;
	}
    }

    *buffer = 0;
    return n;
}

int main (int argc, char **argv) {

	int server_sfd;
	struct sockaddr_in server_addr , my_addr,servaddr;
	char buffer[BUFFLEN];
	char bufferLogin[BUFFLEN];
	char *msj;
	struct in_addr ip_server;
	int fisier_log = 1;
	
	FILE *userLog;
	FILE *pageHtml;
	FILE *error;	
	FILE* status;
	inet_aton (argv[4], &ip_server);
	
	if(argc == 7) {
		char *nume;
		nume = (char*)malloc(255*sizeof(char));
		strcpy(nume,argv[2]);
		char * errorName;
		errorName = (char*)malloc(255*sizeof(char));
		strcpy(errorName,nume);
		strcat(errorName,".stderr");
		
		error = fopen(errorName,"w");
		char * statusName;
		statusName = (char*)malloc(255*sizeof(char));
		strcpy(statusName,nume);
		strcat(statusName,".stdout");
	
		status = fopen(statusName,"w");
		
	}
	
	if(argc = 5)
	{
		fisier_log = 0;
	}	
	
	server_sfd = socket(PF_INET,SOCK_STREAM,0);
	if( server_sfd < 0 ) printf("Error opening socket\n");

	//memset((char *) &server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = ip_server.s_addr;
	server_addr.sin_port = htons(atoi(argv[6]));

	if (connect(server_sfd, (struct sockaddr *) &server_addr, sizeof (struct sockaddr_in)) < 0)
	{
		if(fisier_log == 1)
		{
			fprintf(error,"%s","ERROR connecting");
		}
		else fprintf(stderr,"%s","ERROR connecting");
	}
	send(server_sfd,"200 OK", BUFFLEN,0);
	
	char *token;

	int processID;
	processID = getpid();
	
	char *numeLog;
	char process;
	
	numeLog = (char*)malloc(255*sizeof(char));
	sprintf(numeLog,"%s %d %s","client<",processID,">.log");	
	userLog = fopen(numeLog, "w");
	while(1)
	{
	recv(server_sfd, buffer, BUFFLEN, 0);
	fprintf(userLog,"$ %s",buffer);
	token = (char*)malloc(BUFFLEN*sizeof(char));
	char *temp;

	temp = (char*)malloc(BUFFLEN*sizeof(char));
	memset(temp, 0 , BUFFLEN);
	strcpy(temp,buffer);

	token = strtok(temp," ");



	if(strcmp(token,"download") == 0)
	{
		
		token = strtok(NULL," ");
		char *http;
		http = (char*)malloc(BUFFLEN*sizeof(char));
		char *p ;
		p = strstr(token,"https://");
		char *path;
		path = (char*)malloc(BUFFLEN*sizeof(char));
		strcpy(path,token);
		if(p == NULL)
		{
			http = strtok(token,"/");
			
		}
		else
		{
			token = token + 8;
			http = strtok(token,"/");
			
		}
		
		
		path = path + strlen(http) + 7;
		char *host ;
		host = (char*)malloc(BUFFLEN*sizeof(char));
		strcpy(host,http);
		mkdir(http,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		chdir(http);
		while(http != NULL)
		{
			http = strtok(NULL,"/");
			
			mkdir(http,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
			chdir(http);
		}
		//strcat(http,".html");
		pageHtml = fopen("page.html","w");
		int sockfd;
		int port = 80;
		char server_ip[10];

		struct hostent *site = gethostbyname(host);
		struct in_addr** list_ip = (struct in_addr**) site->h_addr_list;
		strcpy(server_ip, inet_ntoa(*list_ip[0]));
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		memset(&servaddr, 0, sizeof(servaddr));
	  	servaddr.sin_family = AF_INET;
	  	servaddr.sin_port = htons(port);
		
		if (inet_aton(server_ip, &servaddr.sin_addr) <= 0 ) {
	   	
		if(fisier_log == 1)
		{
			fprintf(error,"%s","Adresa IP invalida.");
		}
		else fprintf(stderr,"%s","Adresa IP invalida.");
		fprintf(userLog,"$ %s","Adresa IP invalida.");
	   	exit(-1);
	  	}

		if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0 ) {
				   		
			if(fisier_log == 1)
			{
				fprintf(error,"%s","Eroare la conectare");
			}
			else fprintf(stderr,"%s","Eroare la conectare");
			fprintf(userLog,"$ %s","Eroare la conectare");
	   		exit(-1);
	  	}

		
		
		int i = 0;
		char sendbuf[MAXLEN]; 
	  	char recvbuf[MAXLEN];

		strcpy(sendbuf,"GET ");
		strcat(sendbuf,path);
		strcat(sendbuf," HTTP/1.1\nHost: ");
		strcat(sendbuf,host);
		strcat(sendbuf,"\n\n");
		  
		send(sockfd, sendbuf, strlen(sendbuf),0 );
		char buff[MAXLEN];
		memset(buff, 0, MAXLEN);
		int m;
		m = recv(sockfd, buff, sizeof(buff), 0);
		char* c = strtok(buff," \n");
	
		//printf("%s\n",buff+strlen(c)+1);
		fprintf(pageHtml,"%s",buff);

		int ch = 0;
		while(1){
		    memset(buff, 0, MAXLEN);
		    Readline(sockfd, buff, MAXLEN -1);
		    if ((strstr(buff, "</html") != 0) || (strstr(buff, "</HTML") != 0)) {
			//printf("%s",buff);
			fprintf(pageHtml,"%s",buff);
		      	break;
			
		    }
		//printf("%s",buff);
		fprintf(pageHtml,"%s",buff);
		
		}
		
		fclose(pageHtml);
		
		chdir("..");
		send(server_sfd,"200 OK", BUFFLEN,0);
		exit(1);
	}
	else if(strcmp(token,"exit") == 0)
	{
		if(fisier_log == 1)
		{
			fprintf(status,"%s","Server is closed, bye!");
		}
		else fprintf(stderr,"%s","Server is closed, bye!");
		fprintf(userLog,"%s","Server is closed, bye!");
		send(server_sfd, "ACK", BUFFLEN,0);
		exit(0);
	}
	else send(server_sfd,"200 OK", BUFFLEN,0);
		
	}
	
	
	
	
	
	fclose(userLog);

}
