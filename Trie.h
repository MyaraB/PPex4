#ifndef TRIE_H
#define TRIE_H
#define NUM_LETTERS ((int)26)
#include <stdbool.h>
#define CharPos(c) ((int)c - (int)'a')

typedef struct node
{
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
    bool wordEnd;
}node;

node* createNode();
void insert(node**, char*);
void printUp(node**, char[], int);
void printDown(node**, char[], int);
void freeTrie(node**);

#endif

