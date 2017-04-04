#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "hash.h"
#include "list.h"

int current_size;

int findCommand(List **hashtable,char *cuvant) {
    int i;

    if (hashtable == NULL) 
        return -1;
    for(i = 0; i < current_size ; i++) 
        if (hashtable[i] != NULL) 
            if (findWordInBucket(hashtable[i], cuvant) == 0)
                return i;
    return -1;
}

void addCommand(List **hashtable, char *cuvantDeAdaugat) {
    if (findCommand(hashtable, cuvantDeAdaugat) != -1 )
        return;
    else {
        unsigned int index = 0;

        int i = current_size;

        index = hash(cuvantDeAdaugat, current_size);
        if (index <= i)
            addToList(hashtable[index], cuvantDeAdaugat);
    }
}

void addResizeCommand(List **hashtable, char *cuvantDeAdaugat) {
    unsigned int index = 0;

    int i = current_size;

    index = hash(cuvantDeAdaugat, current_size);
    if (index <= i)
        addToList(hashtable[index], cuvantDeAdaugat);
}
void removeCommand(List **hashtable, char *cuvantDeSters) {
    int index = findCommand(hashtable, cuvantDeSters);

    if ( index == -1 ) {
        return;
    } else {
        int indexOfWord = getIndexOfWord(hashtable[index], cuvantDeSters);

        removeFromList(hashtable[index],indexOfWord);
    }
}


List **clearCommand(List **hashtable, int size) {
    int i,j;

    for(i = 0; i < size ; i++)
        deleteList(hashtable[i]);
    
    hashtable = (List**)malloc(current_size * sizeof(List*));

    for(j = 0; j < current_size; j++)
        hashtable[j] = createList();
    return hashtable;
}

int isNumber(char *number) {
    int i = 0;

    while (i < strlen(number)) {
        if(number[i] >= 48 && number[i] <=57 )
            return 0;
        i++;
    }
    return -1;
}

void printBuckToCons(List **hashtable, int index) {
    if (hashtable[index]->first != NULL) {
        printList(hashtable[index]);
        printf("\n");
    }
}

void printB2File(List **hashtable, int index, FILE *output){
    if (hashtable[index]->first != NULL) {
        printListToFile(hashtable[index], output);
        fprintf(output,"%s","\n");
    }
}

void printToConsoleCommand(List **hashtable) {
    int i;

    for(i = 0; i < current_size ; i++)
        printBuckToCons(hashtable, i);
}

void printToFileCommand(List **hashtable, FILE *output) {
    int i;

    for(i = 0; i < current_size ; i++)
        printB2File(hashtable, i, output);
}

List **resizeDoubleCommand(List **hashtable) {
    int temp_size = current_size;

    List **new_hashtable = (List**)malloc((current_size * 2) * sizeof(List*));

    int i, j, bucket_size = 0;

    current_size = current_size * 2;
    for(i = 0; i < current_size; i++)
        new_hashtable[i] = createList();
    for(j = 0; j < temp_size;j++ ) {
        bucket_size = listSize(hashtable[j]);
        for(i = 0 ; i < bucket_size ; i++) {
            char* cuvant = getWordFromList(hashtable[j], i);

            addResizeCommand(new_hashtable, cuvant);
        }
    }
    return new_hashtable;
}

List **resizeHalveCommand(List **hashtable) {
    int temp_size = current_size;

    List **new_hashtable = (List**)malloc((current_size / 2) * sizeof(List*));

    int i, j, bucket_size = 0;

    current_size = current_size / 2;

    for(i = 0; i < current_size; i++)
        new_hashtable[i] = createList();
    for(i = 0; i < temp_size; i++ ) {
        bucket_size = listSize(hashtable[i]);
        for(j = 0 ; j < bucket_size ; j++) {
            char* cuvant = getWordFromList(hashtable[i], j);

            addResizeCommand(new_hashtable, cuvant);
        }
    }
    return new_hashtable;
}

int main(int argc, char** argv) 
{
    int numberOfInputFiles = argc - 2;

    FILE *input;

    int i, fisierIndex = 2;
	
    char **files = (char**)malloc(numberOfInputFiles * sizeof(char*));

    FILE* fis_out;
	

    if (argc == 1)
        fprintf(stderr,"%s","-1 Lungimea initiala a hashtable neprecizata!\n");
    for(i = 0; i < numberOfInputFiles; i++)
        files[i] = malloc((100) * sizeof(char));
    if (argc >= 2) {
        char buff[2000] = {0};

        List **hashtable;

	if (isNumber(argv[1]) == 0)
		current_size = atoi(argv[1]);
	else {
		fprintf(stderr, "%s", "-1 Parametru invalid\n");
		return -1;
        }

        hashtable = (List**)malloc(current_size * sizeof(List*));

        for(i = 0; i < current_size; i++)
            hashtable[i] = createList();
        if (argc == 2) {
            if (current_size < 1) {
                fprintf(stderr,"%s","-1 Parametru invalid");
                return 0;
            }
            input = stdin;
        } else {
            for(i = 0; i < numberOfInputFiles; i++)
                strcpy(files[i],argv[i+2]);
        }
        if (input == stdin) {
		while (fgets(buff, 20000, input)) {
		    char* cuvant = malloc(20000 * sizeof(char));

		    cuvant = strtok(buff,"\n ");
		    if (cuvant != NULL) {
		        if (strcmp(cuvant,"add") == 0) {
			    cuvant = strtok(NULL," \n");
		            addCommand(hashtable, cuvant);
		        } else if (strcmp(cuvant,"remove") == 0) {
		            cuvant = strtok(NULL," \n");
		            removeCommand(hashtable, cuvant);
		        } else if (strcmp(cuvant,"find") == 0) {
		            cuvant = strtok(NULL," \n");
		            if (findCommand(hashtable, cuvant) != -1) {
		                cuvant = strtok(NULL," \n");
		                if (cuvant != NULL) {
		                    fis_out = fopen(cuvant,"a");
		                    fprintf(fis_out,"%s\n","True");
				    fclose(fis_out);
		                } else
		                    fprintf(stdout,"%s\n","True");
		            } else {
		                cuvant = strtok(NULL," \n");
		                if (cuvant != NULL) {
		                    fis_out = fopen(cuvant,"a");
		                    fprintf(fis_out,"%s\n","False");
				    fclose(fis_out);
		                } else
		                    fprintf(stdout,"%s\n","False");
		            }
		        } else if (strcmp(cuvant,"clear") == 0)
		            hashtable = clearCommand(hashtable, current_size);
		        else if (strcmp(cuvant,"print_bucket") == 0) {
		            int i;

		            cuvant = strtok(NULL," \n");
			    i = atoi(cuvant);

		            if (isNumber(cuvant) == -1 )
		                fprintf(stderr,"%s","-1 Index invalid\n");
		            else if (i >= current_size)
				fprintf(stderr," ");
			    else {
		                cuvant = strtok(NULL," \n");
		                if (cuvant == NULL)
		                    printBuckToCons(hashtable, i);
		                else {
		                    fis_out = fopen(cuvant,"a");
		                    printB2File(hashtable, i, fis_out);
				    fclose(fis_out);
		                }
		            }
		        } else if (strcmp(cuvant,"print") == 0) {
		            cuvant = strtok(NULL," \n");
		            if (cuvant == NULL) 
		                printToConsoleCommand(hashtable);
		            else {
		                fis_out = fopen(cuvant,"a");
		                printToFileCommand(hashtable, fis_out);
				fclose(fis_out);
		            }
		        } else if (strcmp(cuvant,"resize") == 0) {
		             cuvant = strtok(NULL," \n");
		            if (strcmp(cuvant,"double") == 0) {
		                List **new_hashtable;

				int new_size = current_size / 2;

				new_hashtable = resizeDoubleCommand(hashtable);
		                hashtable = clearCommand(hashtable, new_size);
		                hashtable = new_hashtable;
		                
		            } else if (strcmp(cuvant,"halve") == 0) {
		                int par_impar = 0;
		        
		                List **new_hashtable;

				new_hashtable = resizeHalveCommand(hashtable);

		                if (current_size % 2 == 0)
		                    par_impar = 0;
		                else 
		                    par_impar = 1;
		                if (par_impar == 0)
		                    clearCommand(hashtable, current_size*2);
		                else
		                    clearCommand(hashtable, current_size*2+1);
		                hashtable = new_hashtable;
		            } else 
		                fprintf(stderr,"%s","-1 Parametru incorect\n");
		        } else {
		            fprintf(stderr,"%s\n","-1 Comanda invalida !");
			    return 0;				
			}
		    }
		}
	} else {
		while (fisierIndex < argc) {
			input = fopen(files[fisierIndex - 2],"r");
			while (fgets(buff, 2000, input)) {
			    char* cuvant = malloc(2000 * sizeof(char));

			    cuvant = strtok(buff,"\n ");
			    if (cuvant != NULL) {
				if (strcmp(cuvant,"add") == 0) {
				    cuvant = strtok(NULL," \n");
				    addCommand(hashtable, cuvant);
				} else if (strcmp(cuvant,"remove") == 0) {
				    cuvant = strtok(NULL," \n");
				    removeCommand(hashtable, cuvant);
				} else if (strcmp(cuvant,"find") == 0) {
				    cuvant = strtok(NULL," \n");
				    if (findCommand(hashtable, cuvant) != -1) {
				        cuvant = strtok(NULL," \n");
				        if (cuvant != NULL) {
				            fis_out = fopen(cuvant,"a");
				            fprintf(fis_out,"%s\n","True");
					    fclose(fis_out);
				        } else
				            fprintf(stdout,"%s\n","True");
				    } else {
				        cuvant = strtok(NULL," \n");
				        if (cuvant != NULL) {
				            fis_out = fopen(cuvant,"a");
				            fprintf(fis_out,"%s\n","False");
					    fclose(fis_out);
				        } else
				            fprintf(stdout,"%s\n","False");
				    }
				} else if (strcmp(cuvant,"clear") == 0) {
					int s = current_size;

					hashtable = clearCommand(hashtable, s);
				} else if (strcmp(cuvant,"print_bucket")==0) {
				    int i;

				    cuvant = strtok(NULL," \n");
				    i = atoi(cuvant);

				    if (isNumber(cuvant) == -1)
				        fprintf(stderr,"%s","-1 Nu e int\n");
				    else if (i >= current_size)
				        fprintf(stderr," ");
				    else {
				        cuvant = strtok(NULL," \n");
				        if (cuvant == NULL)
				            printBuckToCons(hashtable, i);
				        else {
				            fis_out = fopen(cuvant,"a");
				            printB2File(hashtable, i, fis_out);
					    fclose(fis_out);
				        }
				    }
				} else if (strcmp(cuvant,"print") == 0) {
				    cuvant = strtok(NULL," \n");
				    if (cuvant == NULL) 
				        printToConsoleCommand(hashtable);
				    else {
				        fis_out = fopen(cuvant,"a");
				        printToFileCommand(hashtable, fis_out);
					fclose(fis_out);
				    }
				} else if (strcmp(cuvant,"resize") == 0) {
				     cuvant = strtok(NULL," \n");
				    if (strcmp(cuvant,"double") == 0) {
				        List **new;

					int s = current_size / 2;

					new = resizeDoubleCommand(hashtable);

				        hashtable = clearCommand(hashtable, s);
				        hashtable = new;
				        
				    } else if (strcmp(cuvant,"halve") == 0) {
				        int par, impar, par_impar = 0;
				
				        List **new;

					new = resizeHalveCommand(hashtable);
					par = current_size * 2;
					impar = current_size * 2 + 1;

				        if (current_size % 2 == 0)
				            par_impar = 0;
				        else 
				            par_impar = 1;
				        if (par_impar == 0)
				            clearCommand(hashtable, par);
				        else
				            clearCommand(hashtable, impar);
				        hashtable = new;
				    } else 
				        fprintf(stderr,"%s","-1 Error\n");
				} else {
				    fprintf(stderr,"%s\n","-1 Error");
				    return 0;
				}
			    }
			
			}
			fisierIndex++;
		}
	}
    }
	fclose(input);
    return 0;
}

