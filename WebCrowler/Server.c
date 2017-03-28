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
#include <dirent.h>
#include <sys/stat.h>

#define MAX_CLIENTS 10
#define BUFFLEN 1024


int main (int argc, char **argv) {
	
	int server_sfd, newsockfd;	
	struct sockaddr_in server_addr, cli_addr;
	char buffer [BUFFLEN];
	int i,n;
	int nrClienti = 0;
	char **adreseIp = (char **) malloc (255*sizeof(char*));
	int *port = (int *) malloc (255*sizeof(int*));
	FILE* status,*error;
	char in[BUFFLEN];

	fd_set read_fds;
	fd_set tmp_fds;
	int fdmax;
	

	FD_ZERO(&read_fds);
	FD_ZERO(&tmp_fds);
	int fisier_log = 0;
	server_sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sfd < 0){
		if(fisier_log == 1)
		{
			fprintf(error,"%s","Error opening socket !\n");
		}
		else fprintf(stderr,"%s","Error opening socket !\n");
		
	}

	int recursive = 0;
	int everything = 0;
		
	
	if(argc == 5)
	{
		recursive = 1;
		everything = 1;
	}
	
	if(argc == 6)
	{
	
	fisier_log = 1;
		if(strcmp(argv[1],"-r") == 0)
		{
			recursive = 1;
		}
		else if(strcmp(argv[1],"-e") == 0)
		{
			everything = 1;
		}
	memset((char *) &server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr =INADDR_ANY;
	server_addr.sin_port = htons(atoi(argv[5]));

	char *nume;
	nume = (char*)malloc(255*sizeof(char));
	strcpy(nume,argv[3]);
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
	

	if(argc == 7)
	{
		fisier_log = 1;
		recursive = 1;
		everything = 1;
		memset((char *) &server_addr, 0, sizeof(server_addr));
		server_addr.sin_family = AF_INET;
		server_addr.sin_addr.s_addr =INADDR_ANY;
		server_addr.sin_port = htons(atoi(argv[6]));
		
		char *nume;
		nume = (char*)malloc(255*sizeof(char));
		strcpy(nume,argv[4]);
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

	
	//server_addr.sin_port = htons(atoi(argv[1]));

	if( bind(server_sfd, (struct sockaddr *) &server_addr , sizeof(struct sockaddr) ) < 0){
		if(fisier_log == 1)
		{
			fprintf(error,"%s","Error on binding !\n");
		}
		else fprintf(stderr,"%s","Error on binding !\n");
	}

	listen(server_sfd, MAX_CLIENTS);
	
	FD_SET(server_sfd, &read_fds);
	//FD_SET(STDIN_FILENO, &read_fds);
	fdmax = server_sfd;

	int clilen;
	if(fisier_log == 1)
	{
		fprintf(status,"%s","Server started !\n");
	}
	else printf("Server started !\n");
	
	int check = 0;
	while(check == 0)
	{
	
	
	tmp_fds = read_fds;
	
	if(select(fdmax+1, &tmp_fds, NULL, NULL, NULL) == -1){
			if(fisier_log == 1)
			{
				fprintf(error,"%s","Error in select!\n");
			}	
			else printf("Error in select!\n");
	}
	

	for( i = 0; i < fdmax+1 ; i++)
	{
		if(FD_ISSET(i, &tmp_fds))
		{
			if(i == server_sfd)
			{
				clilen = sizeof(cli_addr);
				newsockfd = accept(server_sfd, (struct sockaddr *) &cli_addr, &clilen);
				if( newsockfd < 0){
					if( fisier_log == 1)
					{
						fprintf(error,"%d Error in accept!\n",newsockfd);
					}
					else printf("%d Error in accept!\n",newsockfd);
				} else {
					FD_SET(newsockfd, &read_fds);
					if(newsockfd > fdmax){
						fdmax = newsockfd;
					if(fisier_log == 1)
					{
						fprintf(status,"%s %d .\n","S-a conectat clientul ",newsockfd);
					}
					else fprintf(stderr,"%s %d .\n","S-a conectat clientul ",newsockfd);
					
					adreseIp[nrClienti] =(char*) calloc (255, sizeof(char));
					strcpy(adreseIp[nrClienti],inet_ntoa(cli_addr.sin_addr));
					port[nrClienti] = ntohs(cli_addr.sin_port); 
					nrClienti++;
					
					}
				
				}
			} else {
				
				memset(buffer, 0 , BUFFLEN);				
				n = recv(i, buffer, BUFFLEN, 0);
				
			
				if( n <= 0 ) {
					if( n == 0 )
					{
						if( fisier_log == 1)
						{
							fprintf(status,"Clientul %d s-a deconectat.\n", i);  
						}
						else fprintf(stderr,"Clientul %d s-a deconectat.\n", i); 
					}					
					else
					{ 
						if(fisier_log ==1)
						{
							fprintf(error,"%s","Error in recive !\n");
						}
						else fprintf(stderr,"%s","Error in recive !\n");
					}
				close(i);
				FD_CLR(i , &read_fds);
				nrClienti -= 1;
				
				} else {
				
				
					char *token;
					char in[BUFFLEN];
					memset(in, 0 , BUFFLEN);
					fgets(in,BUFFLEN,stdin);

					char *temp;
					temp = (char*)malloc(BUFFLEN*sizeof(char));
					memset(temp, 0 , BUFFLEN);
					strcpy(temp,in);
								
					token = (char*)malloc(BUFFLEN*sizeof(char));
	
					token = strtok(temp," ");
					if(nrClienti == 5)
					{
						if(strcmp(token,"download") == 0)
						{
							send(i,in,BUFFLEN,0);
							
						}
					}
					if(strcmp(token,"status\n") == 0)
					{
						send(i,"status",BUFFLEN,0);
						int x,y;
						for(x = 0; x < nrClienti; x++)
						{
							if(fisier_log == 1)
							{
								fprintf(status,"Clientul:%d IP: %s PORT: %d\n",x,adreseIp[x],port[x]);
							}
							else	fprintf(stderr,"%s %d\n",adreseIp[x],port[x]);
						
						
						}
					}
					if(strcmp(token,"exit\n") == 0)
					{
						fclose(status);
						fclose(error);
						int j;
						for( j = 0; j < fdmax+1 ; j++)
						{
							char *ack;
							send(j,"exit",BUFFLEN,0);
							recv(j,ack,BUFFLEN,0);
							close(j);
							
						}
						
						check = 1;
						
					}
				
				}	

					
					
				}
			}
		} 
	
	}
	
	
}
	





