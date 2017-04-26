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

char **make_error_codes()
{
	char **error_codes = (char*)malloc(11 * sizeof(char*)) ;
	int er;
	for(er = 1; er < 11; er++)
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
	return error_codes;
}


int main (int argc, char **argv) {
	char **err = (char*)malloc(11 * sizeof(char*)) ;
	err	= make_error_codes();
	
	int server_sfd, newsockfd;	
	struct sockaddr_in server_addr, cli_addr;
	char buffer [BUFFLEN];
	int i,n;
	bool login = false;
	int loginNereusit;
	char *ack;
	ack = (char*)malloc(10*sizeof(char));
	
	/*Citirea din fisier*/
	int N;
	FILE *users;
	users = fopen( argv[2], "r+");
	fscanf(users, "%d\n", &N);

	
	char **cuvinte = (char **) malloc ((N)*sizeof(char*));
	char **cuvinteTemp = (char **) malloc ((N)*sizeof(char*));
	char **userList = (char **) malloc ((N)*sizeof(char*));
	char **conectedUsers = (char **) malloc ((N)*sizeof(char*));
	char **solds = (char **) malloc ((N)*sizeof(char*));
	int k,m;
	for(k = 0 ; k < N ; k++)
	{
		cuvinte[k] = (char*) calloc ((50), sizeof(char));
		cuvinteTemp[k] = (char*) calloc ((50), sizeof(char));
		userList[k] = (char*) calloc ((50), sizeof(char));
		conectedUsers[k] = (char*) calloc (BUFFLEN, sizeof(char));
		solds[k] = (char*) calloc (BUFFLEN, sizeof(char));
		strcpy(conectedUsers[k], "0");
	}
	for(k = 0 ; k < N ; k++)
	{
		fgets(cuvinte[k], 50, users);		
	}
	

	fd_set read_fds;
	fd_set tmp_fds;
	int fdmax;
	
	if(argc < 3) {
		perror("Usage :./Server <port> <user_config> <shared_files>\n");
		exit(1);
	}

	FD_ZERO(&read_fds);
	FD_ZERO(&tmp_fds);
	
	server_sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sfd < 0){
		printf("Error opening socket !\n");
	}

	memset((char *) &server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr =INADDR_ANY;
	server_addr.sin_port = htons(atoi(argv[1]));

	if( bind(server_sfd, (struct sockaddr *) &server_addr , sizeof(struct sockaddr) ) < 0){
		printf("Error on binding !\n");
	}

	listen(server_sfd, MAX_CLIENTS);
	
	FD_SET(server_sfd, &read_fds);
	//FD_SET(STDIN_FILENO, &read_fds);
	fdmax = server_sfd;
	fclose(users);
	int clilen;
	printf("Server started !\n");

	int quit = 0;
	char *sold = malloc(BUFFLEN * sizeof(char));
	int pos_of_sold ;
	int pos_last_line[N];
	int jj;
	int incercariUseri[N];
	int l;
	for(l = 0; l < N; l++)
		incercariUseri[l] = 0;
	
	for(jj = 0; jj < N; jj++) {
		pos_last_line[jj] = 0;
	}
		
	char *card_number, *pin;
	card_number = (char*)malloc(255*sizeof(char));
	pin = (char*)malloc(255*sizeof(char));
	int b = 0;
	while(quit != 1)
	{
	
	tmp_fds = read_fds;
	
	if(select(fdmax+1, &tmp_fds, NULL, NULL, NULL) == -1){
			printf("Error in select!\n");
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
					printf("%d Error in accept!\n",newsockfd);
				} else {
					FD_SET(newsockfd, &read_fds);
					if(newsockfd > fdmax){
						fdmax = newsockfd;
					fprintf(stderr,"%s","S-a conectat un Client.\n");
					loginNereusit = 0;
					}
				}
			} else {
				memset(buffer, 0 , BUFFLEN);
				n = recv(i, buffer, BUFFLEN, 0);
			
				if( n <= 0 ) {
					if( n == 0 ) printf("Clientul %d s-a deconectat.\n", i); 
					else printf("Error in recive !\n");
				close(i);
				FD_CLR(i , &read_fds);
				
				} else {
					char *token,*userFile;
					
					char *tmp;
					tmp = (char*)malloc(BUFFLEN*sizeof(char));
					strcpy(tmp,buffer);

					int j = 0;
					char *card_number, *pin;
					card_number = (char*)malloc(255*sizeof(char));
					pin = (char*)malloc(255*sizeof(char));
					bool card_number_check = false;
					bool pin_check = false;
					char *card_number_pin;
					card_number_pin = malloc(11 * sizeof(char));
					strcpy(card_number_pin, card_number);
					strcat(card_number_pin, pin);
					bool already_conected = false;
					int g = 0;

					token = strtok(tmp," ");
					if(strcmp(token,"login") == 0 && i > 0)
					{
						users = fopen( argv[2], "r+");
						fscanf(users, "%d\n", &N);
							while(j != 2)
							{
								if(j == 0)
								{
									token = strtok(NULL," ");
									strcpy(card_number,token);
									j++;
								} else if(j ==1 )
								{
									token = strtok(NULL," ");
									strcpy(pin,token);
									j++;						
								}		
							}
							for(k = 0; k < N;k++)
							{
								int nn = 0;
								
								fgets(cuvinte[k], 50, users);
								strcpy(cuvinteTemp[k], cuvinte[k]);
								
								pos_last_line[k] = strlen(cuvinteTemp[k]);

								char *tkn;
								pos_of_sold = 1;
								if (k != 0) {
									pos_of_sold = 1;
									int ii;
									for(ii = 0; ii < k; ii++)
										pos_of_sold += pos_last_line[ii];
								}
								tkn = (char*)malloc(255*sizeof(char));
								tkn = strtok(cuvinteTemp[k]," ");
								pos_of_sold += strlen(tkn);
								tkn = strtok(NULL," ");
								pos_of_sold += strlen(tkn);
								tkn = strtok(NULL," ");
								pos_of_sold += strlen(tkn);
								if(strcmp(tkn, card_number) == 0)
								{
									if(strcmp(conectedUsers[k],"BLOCKED") == 0) {
										send(i, err[5], BUFFLEN, 0);
										break;
									}
									card_number_check = true;
									tkn = strtok(NULL," ");	
									pos_of_sold += strlen(tkn);
									if(strncmp(tkn, pin,4) == 0){
										pin_check = true;
										login = true;
										tkn = strtok(NULL," ");
										pos_of_sold += strlen(tkn);
										pos_of_sold += 5;
										tkn = strtok(NULL," ");
										strcpy(sold, tkn);
										char *msj;
										msj = (char*) malloc(255*sizeof(char));
										strcat(msj,card_number);
										char *pos_sold = malloc(BUFFLEN * sizeof(char));
										sprintf(pos_sold, "%d", pos_of_sold);
										if (strncmp(conectedUsers[k], "0", 1) == 0) {
											fprintf(stderr,"Login reusit : %s\n",card_number);
											strcpy(conectedUsers[k], "1");
											char *pos_of_user = malloc(BUFFLEN * sizeof(char));
											sprintf(pos_of_user, "%d", k);
											strcpy(solds[k], sold);
											send(i, "true", BUFFLEN, 0);
											send(i, pos_of_user, BUFFLEN, 0);
											//send(i, sold, BUFFLEN, 0);
											send(i, pos_sold, BUFFLEN, 0);
											send(i, msj, BUFFLEN, 0);
											fclose(users);
											break;
										} else if (strncmp(conectedUsers[k], "1", 1) == 0) {
											char *check_user = malloc(BUFFLEN * sizeof(char));
											
											
											if(incercariUseri[k] == 3) {
												strcpy(conectedUsers[k], "BLOCKED");
												send(i, err[5], BUFFLEN, 0);
											}
											else {
												send(i, err[2], BUFFLEN, 0);
												incercariUseri[k]++;
											}
											break;
										}	
										
									} else {
										char *check_user = malloc(BUFFLEN * sizeof(char));
										
										
										if(incercariUseri[k] == 3) {
											send(i, err[5], BUFFLEN, 0);
											strcpy(conectedUsers[k], "BLOCKED");
										}
										else {
											send(i, err[3], BUFFLEN, 0);
											incercariUseri[k]++;
										}
									}
								} else {
									//printf(tkn);	
									if(g == N - 1)
										send(i, err[4], BUFFLEN, 0);
									else 
										g++;			
								}
									
							}
							//fclose(users);
					} else if (strcmp(token, "logout") == 0 && i > 0) {
						char *logout = malloc(BUFFLEN * sizeof(char));				
						recv(i, logout, BUFFLEN, 0);
						strcpy(conectedUsers[atoi(logout)], "0");
						send(i,"ATM> Deconectare de la bancomat", BUFFLEN, 0);
					} else if (strcmp(token, "listsold") == 0 && i > 0) {
						char *pos_user = malloc(BUFFLEN * sizeof(char));
						recv(i, pos_user, BUFFLEN, 0);
						int pos_of_user = atoi(pos_user);
						send(i, solds[pos_of_user], BUFFLEN, 0);
					} else if (strcmp(token, "getmoney") == 0 && i > 0) {
						char *pos_user = malloc(BUFFLEN * sizeof(char));
						recv(i, pos_user, BUFFLEN, 0);
						int pos_of_user = atoi(pos_user);
						char *money = malloc(BUFFLEN * sizeof(char));
						money = strtok(NULL," \n");
						if (atof(money) > atof(solds[pos_of_user]) )
							send(i, err[8], BUFFLEN, 0);
						else {
							users = fopen( argv[2], "r+");
							double rest = atof(solds[pos_of_user]) - atof(money);
							sprintf(solds[pos_of_user], "%.2f", rest);
							char *response = malloc(BUFFLEN * sizeof(char));
							strcpy(response,"ATM> Suma ");
							strcat(response, money);
							strcat(response, " retrasa cu succes\n");
							send(i, response, BUFFLEN, 0);
							fclose(users);
						}
					} else if (strcmp(token, "putmoney") == 0 && i > 0) {
						char *pos_user = malloc(BUFFLEN * sizeof(char));
						recv(i, pos_user, BUFFLEN, 0);
						int pos_of_user = atoi(pos_user);
						char *money = malloc(20 * sizeof(char));
						money = strtok(NULL," \n");
						users = fopen( argv[2], "r+");
						double sum = atof(solds[pos_of_user]) + atof(money);
						sprintf(solds[pos_of_user], "%.2f", sum);
						char *response = malloc(BUFFLEN * sizeof(char));
						strcpy(response,"ATM> Suma depusa cu succes\n");
						send(i, response, BUFFLEN, 0);
						fclose(users);
						/*char *money = malloc(20 * sizeof(char));
						users = fopen( argv[2], "r+");
						char *final_sold = malloc(BUFFLEN * sizeof(char));
						char *pos_sold = malloc(BUFFLEN * sizeof(char));
						recv(i, final_sold, BUFFLEN, 0);
						double rest = atof(final_sold);
						sprintf(final_sold, "%.2f", rest);
						recv(i, pos_sold, BUFFLEN, 0);
						int p = atoi(pos_sold);
						fseek(users, p + 1, SEEK_SET);
						fputs(final_sold , users);
						char *response = malloc(BUFFLEN * sizeof(char));
						strcpy(response,"ATM> Suma depusa cu succes\n");
						send(i, response, BUFFLEN, 0);
						fclose(users);*/
					} else if (strncmp(token, "quit",4) == 0 && i>0) {
						char *quit = malloc(BUFFLEN * sizeof(char));				
						recv(i, quit, BUFFLEN, 0);
						strcpy(conectedUsers[atoi(quit)], "0");
					}else {
						fprintf(stderr,"%s",buffer);
					}				
					
				}
			}
		} 
	
	}
	}	

	close(server_sfd);
	
	
}
	





