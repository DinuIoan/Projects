#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"
typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *createNode();

typedef struct List {
    int size_of_list;
    Node *first;
} List;

List *createList();
void addToList(List *list,char *word);
void removeFromList(List *list,int index);
int getIndexOfWord(List *list, char *word);
char *getWordFromList(List *list, int index);
int listSize(List *list);
int findWordInBucket(List *list, char *word);
void printList(List *list);
void printListToFile(List *list, FILE *output);
void deleteList(List *list);

#endif /* LIST_H */

