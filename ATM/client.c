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

#define BUFFLEN 1024
#define MAX_CLIENTS 10

char **make_error_codes()
{
	char **error_codes = (char*)malloc(12 * sizeof(char*)) ;
	int er;
	for(er = 1; er < 12; er++)
		error_codes[er] = malloc(50 * sizeof(char));
	strcpy(error_codes[1],"ATM> -1 : Clientul nu este autentificat\n");
	strcpy(error_codes[2],"ATM> -2 : Sesiune deja deschisa\n");
	strcpy(error_codes[3],"ATM> -3 : Pin gresit\n");
	strcpy(error_codes[4],"ATM> -4 : Numar card inexistent\n");
	strcpy(error_codes[5],"ATM> -5 : Card blocat\n");
	strcpy(error_codes[6],"ATM> -6 : Operatie esuata\n");
	strcpy(error_codes[7],"ATM> -7 : Deblocare esuata\n");
	strcpy(error_codes[8],"ATM> -8 : Fonduri insuficiente\n");
	strcpy(error_codes[9],"ATM> -9 : Suma nu e multiplu de 10\n");
	strcpy(error_codes[10],"ATM> -10 :  Eroare la apel connect/bind/accept\n");
	strcpy(error_codes[11],"ATM> -11 :  Te rog, introdu o comanda corecta\n");
	return error_codes;
}

int main (int argc, char **argv) {
	char **err = (char*)malloc(12 * sizeof(char*)) ;
	err	= make_error_codes();
		
	int server_sfd;
	struct sockaddr_in server_addr , my_addr;
	char buffer[BUFFLEN];
	char bufferLogin[BUFFLEN];
	char *msj;
	struct in_addr ip_server;
	bool login = false;
	char *loginCheck;
	loginCheck = (char*)malloc(BUFFLEN*sizeof(char));
	char *username;
	username = (char*)malloc(255*sizeof(char));
	char *codEroare3, *codEroare8, *codEroare11;
	codEroare3 = (char*)malloc(BUFFLEN*sizeof(char));
	codEroare8 = (char*)malloc(BUFFLEN*sizeof(char));
	codEroare11 = (char*)malloc(BUFFLEN*sizeof(char));
	codEroare11 = "-11 Utilizator inexistent !";
	int incercariLogin = 0;
	FILE *userLog;
	

	inet_aton (argv[1], &ip_server);
	
	if(argc < 2) {
		fprintf(stderr,"Usage : %s ip_server port_server\n", argv[0]);	
		exit(1);
	}
	
	server_sfd = socket(PF_INET,SOCK_STREAM,0);
	if( server_sfd < 0 ) printf("Error opening socket\n");

	//memset((char *) &server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = ip_server.s_addr;
	server_addr.sin_port = htons(atoi(argv[2]));

	if (connect(server_sfd, (struct sockaddr *) &server_addr, sizeof (struct sockaddr_in)) < 0) {
		printf(err[10]);
		exit(1);
	}
	
	char *token;

	int processID;
	processID = getpid();
	
	char *numeLog;
	char process;
	char *sold;
	sold = (char*)malloc(BUFFLEN*sizeof(char));
	char *pos_sold = malloc(BUFFLEN * sizeof(char));
	char *pos_of_user = malloc(BUFFLEN * sizeof(char));
	numeLog = (char*)malloc(255*sizeof(char));
	sprintf(numeLog,"%s %d %s","client-<",&processID,">.log");	
	userLog = fopen(numeLog, "w");
	while(1)
	{
		
		if( login == true )
		{		
			
			incercariLogin = 0;
			memset(bufferLogin, 0 , BUFFLEN);
			fgets(bufferLogin,BUFFLEN,stdin);
			char *temp;
			temp = (char*)malloc(255*sizeof(char));
			strcpy(temp,bufferLogin);
			token = strtok(temp," ");
			fprintf(userLog,"%s",bufferLogin);
			if(strcmp(token, "login") == 0 )
			{
				fprintf(stderr,err[2]);
				fprintf(userLog,"%s",err[2]);
			} else if(strcmp(token,"logout\n") == 0) {
				char *logout;
				logout = (char*)malloc(BUFFLEN*sizeof(char));
				login = false;
				send(server_sfd, "logout" , BUFFLEN, 0);
				send(server_sfd, pos_of_user, BUFFLEN, 0);
				recv(server_sfd, logout, BUFFLEN, 0);
				fprintf(userLog,"%s\n",logout);
				fprintf(stderr,"%s\n",logout);
			} else if (strcmp(token,"listsold\n") == 0) {
				
				char *sold;
				sold = (char*)malloc(BUFFLEN*sizeof(char));
				send(server_sfd, "listsold" , BUFFLEN, 0);
				send(server_sfd, pos_of_user, BUFFLEN, 0);
				//fprintf(userLog,"%s","listsold\n");
				recv(server_sfd, sold, BUFFLEN, 0);
				float soldd = atof(sold);
				fprintf(userLog,"ATM> %.2f\n",soldd);
				fprintf(stderr,"ATM> %.2f\n",soldd);
			} else if (strcmp(token, "getmoney") == 0) {
				char *money;
				money = (char*)malloc(BUFFLEN*sizeof(char));
				token = strtok(NULL," ");
				strcpy(money, token);
				if(atoi(money) % 10 != 0 ) {
					printf(err[9]);
					fprintf(userLog,"%s",err[9]);
				} else {
					char *getmoneycommand = malloc(BUFFLEN * sizeof(char));
					strcpy(getmoneycommand, "getmoney ");
					strcat(getmoneycommand, money);
					send(server_sfd, getmoneycommand , BUFFLEN, 0);
					send(server_sfd, pos_of_user, BUFFLEN, 0);
					recv(server_sfd, getmoneycommand, BUFFLEN, 0);
					fprintf(userLog,"%s",getmoneycommand);
					fprintf(stderr,"%s",getmoneycommand);
				}
			} else if ((strcmp(token, "putmoney") == 0)) {
				
				char *money;
				money = (char*)malloc(BUFFLEN*sizeof(char));
				token = strtok(NULL," ");
				strcpy(money, token);
				char *putmoney;
				putmoney = (char*)malloc(BUFFLEN*sizeof(char));
				strcpy(putmoney, "putmoney ");
				strcat(putmoney, money);
				send(server_sfd, putmoney , BUFFLEN, 0);
				send(server_sfd, pos_of_user, BUFFLEN, 0);
				recv(server_sfd, putmoney, BUFFLEN, 0);
				fprintf(userLog,"%s",putmoney);
				fprintf(stderr,"%s",putmoney);
			} else if(strcmp(token,"quit\n") == 0) {
				fprintf(userLog,"%s","quit");
				send(server_sfd, token , BUFFLEN, 0);
				send(server_sfd, pos_of_user , BUFFLEN, 0);
				close(server_sfd);
				break;
			} else {
				fprintf(userLog,"%s",err[11]);
				fprintf(stderr,"%s",err[11]);
				send(server_sfd, "Comanda gresita!\n", BUFFLEN, 0);
				
			}			
		}
		else 
		{
			memset(buffer, 0 , BUFFLEN);
			fgets(buffer,BUFFLEN,stdin);
			fprintf(userLog,"$ %s",buffer);
			
			char *tmp,*quit;
			tmp = (char*)malloc(255*sizeof(char));
			memset(tmp, 0 , 255);
			strcpy(tmp,buffer);
			
			quit = (char*)malloc(255*sizeof(char));
			memset(quit, 0 , 255);
			strcpy(quit,buffer);
			
			char *pch = strstr(tmp,"login");
			if(!pch)
			{
				if( strcmp(quit,"quit\n") != 0 )
				{
					
					fprintf(stderr,"%s",err[1]);
					fprintf(userLog,"%s",err[1]);
				} else
				{
					send(server_sfd, "quiting", BUFFLEN, 0);
					//fprintf(userLog,"%s","quit");
					close(server_sfd);
					break;
				}
				
			}
			else	
			{
				send(server_sfd, buffer , BUFFLEN, 0);
				recv(server_sfd, loginCheck, BUFFLEN, 0);
				if(strcmp(loginCheck,"true") == 0)
				{
					login = true;
					recv(server_sfd, pos_of_user, BUFFLEN, 0);
					//recv(server_sfd, sold, BUFFLEN, 0);	
					recv(server_sfd, pos_sold, BUFFLEN, 0);	
					recv(server_sfd, username, BUFFLEN, 0);	
					printf("Login reusit. Bun venit!"); printf("\n");
				} else if (strcmp(loginCheck, err[5]) == 0) {
					printf(err[5]);
				} else if (strcmp(loginCheck, err[2]) == 0 ) {
					incercariLogin++;
					if (incercariLogin == 3) {
						printf(err[5]);
						exit(0);
					} else {
						printf(err[2]);
						close(server_sfd);
						break;
					}
				} else if (strcmp(loginCheck, err[4]) == 0) {
					incercariLogin++;
					if (incercariLogin == 3) {
						printf(err[5]);
						exit(0);
					} else {
						printf(err[4]);
					}
				} else if (strcmp(loginCheck, err[3]) == 0) {
					incercariLogin++;
					if (incercariLogin == 3) {
						printf(err[5]);
						exit(0);
					} else {
						printf(err[3]);
					}
				}
				
			}
		}
	}
	

	
	
	fclose(userLog);
	return 0;

}
