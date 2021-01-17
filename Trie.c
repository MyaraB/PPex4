#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "Trie.h"

/**
 * node "builder"
 * */
node* createNode(){
    node* n = (node*)malloc(sizeof(node));
    n->count = 0;
    n->wordEnd = false;
    for(int i=0; i<NUM_LETTERS; i++)
        n->children[i] = NULL;
    return n;
}
/**
 * inserts a word to the trie.
 * */
void insert(node** parent, char* val){
    int let;
    node* n = *parent;
    int len = (int)strlen(val);
    for (int i = 0; i < len; i++){
        let = CharPos(val[i]);
        if (!n->children[let]){
            n->children[let] = createNode();
            n->children[let]->letter = val[i];
        }
        n = n->children[let];
    }
    n->wordEnd = true;
    n->count++;
}
/**
 * prints all trie from parent onwards lexicographicly.
 * */
void printUp(node** parent, char word[], int pos){
    node* n = *parent;
    if (n == NULL)
        return;
    if (n->wordEnd){
        word[pos] = '\0';
        printf("%s \t %ld \n",word, n->count);
    }

    for (int i = 0; i < NUM_LETTERS; i++)
        if(n->children[i] != NULL){
            word[pos] = n->children[i]->letter;
            printUp(&(n->children[i]), word, pos + 1);       
        }        
}
/**
 * prints all trie from parent onwards lexicographicly **reversed**.
 * */
void printDown(node** parent, char word[], int pos){
    node* n = *parent;
    if (n == NULL)
        return;
   
    for (int i = NUM_LETTERS - 1; i >= 0; i--){
            if(n->children[i] != NULL){
                word[pos] = n->children[i]->letter;
                printDown(&(n->children[i]), word, pos + 1);       
            }
        }
    if(n->wordEnd){
        word[pos] = '\0';
        printf("%s \t %ld \n",word, n->count);
    }    
}
/**
 * free all memory space that was dedicated to the trie from parent onwards.
 * */
void freeTrie(node** parent){
    node* n = *parent;
    for (int i = 0; i < NUM_LETTERS; i++){
        if (n->children[i] != NULL){
            freeTrie(&(n->children[i]));
            }
	}
	free(n);
}
