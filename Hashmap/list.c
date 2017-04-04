#include "list.h"
Node *createNode() {
    Node *nod = malloc(sizeof(Node));

    nod->word = malloc(50 * sizeof(char));
    nod->next = NULL;
    return nod;
}

Node *createNodeAdd(char *word) {
    Node *nod = malloc(sizeof(Node));

    nod->word = malloc((strlen(word)+1) * sizeof(char));
    nod->next = NULL;

    return nod;
}

void deleteNode(Node *nod) {
    if (nod != NULL) 
	free(nod);
}

List *createList() {
    List *list = malloc(sizeof(long));

    list->first = NULL;
    list->size_of_list = 0;
    return list;
}

void addToList(List *list, char *word) {
    Node *nod = createNodeAdd(word);

    if ( list->first == NULL ) {
	strcpy(nod->word, word);
	nod->next = NULL;
        list->first = nod;
        list->size_of_list++;
    } else {
        nod = list->first;
	while (nod->next != NULL)
		nod = nod->next;
        nod->next = createNode();
        strcpy(nod->next->word, word);
        list->size_of_list++;
    }
}

void removeFromList(List *list, int index) {
    if (index == 0) {
        Node *nod = createNode();

        nod = list->first;
        list->first = list->first->next;
        deleteNode(nod);
        list->size_of_list--;
    } else {
        Node *pivot = createNode();

        Node *nod;

        pivot = list->first;
        while (index > 1) {
            pivot = pivot->next;
            index--;
        }
        nod = createNode();

        nod = pivot->next;
        pivot->next = pivot->next->next;
        deleteNode(nod);
        list->size_of_list--;
    }
}

int findWordInBucket(List *list, char *word) {
    if (list != NULL){
        Node *nod = createNode();

        nod = list->first;
        while (nod != NULL) {
            if (strcmp(word,nod->word) == 0)
                return 0;
            nod = nod->next;
        }
    }
    return -1;
}

int listSize(List *list) {
    return list->size_of_list;
}

char *getWordFromList(List *list, int index) {
    int i = 0;

    Node *nod = createNode();

    nod = list->first;
    if(list == NULL)
        return NULL;
    else {
        while (i < index) {
            i++;
            nod = nod->next;
        }
    }
    return nod->word;
}

int getIndexOfWord(List *list, char *word) {
    if (list != NULL){
        int index = 0;

        Node *nod = createNode();

        nod = list->first;
        while (nod != NULL) {
            if (strcmp(word,nod->word) == 0)
                return index;
            index++;
            nod = nod->next;
        }
    }
    return -1;
}


void printList(List *list) {
    if (list != NULL) {
        Node *nod = createNode();

        nod = list->first;
        while (nod != NULL) {
            printf("%s",nod->word);
            nod = nod->next;
            if (nod != NULL)
                printf(" ");
        }
    }
}

void printListToFile(List *list, FILE *output) {
    if (list != NULL) {
        Node *nod = createNode();

        nod = list->first;
        while (nod != NULL) {
            fprintf(output,"%s",nod->word);
            nod = nod->next;
            if (nod != NULL)
                fprintf(output,"%s"," ");
        }
    }
}

void deleteList(List *list) {
    if (list != NULL) {
        Node *nod = createNode();

        Node *next = createNode();

        nod = list->first;
        while (nod != NULL) {
            next = nod->next;
            free(nod);
            nod = next;
        }
        free(list);
    }
    
}

