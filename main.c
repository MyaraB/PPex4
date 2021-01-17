#include "Trie.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define AMOUNT 30

int main(int charc, char* wordc[]){
	char* word = (char*)malloc(sizeof(char)*256);
	int tst=0;	
	int capacity=256;
	bool upsideDown=false;
	char* temp=NULL;
	int count=0;
	char c=getchar();
	node* source = createNode();
	/**
	*checking of we recieve the letter "r" after frequency
	**/	
	if(charc==2 && strcmp(wordc[1],"r")==0)
	upsideDown=true;
	/**
	*as long as we havent reached the end of the file and the characters are from the abc
	**/	
	while(c!=EOF || (c==EOF && tst!=1)){
		if(c >= 65 && c <= 90){c = c+32;}
		if(c >= 97 && c <= 122 && c != ' ' && c!= '\n' && c !='\0' && c !='\t'){
			if(capacity == count){
				temp=(char*)realloc(word,(capacity+AMOUNT)*sizeof(char));
				capacity+=AMOUNT;
				if(word != NULL && temp == NULL){
				free(word);
				return -1;
			}
			word = (char*)calloc(capacity,sizeof(char));
			strcpy(word,temp);
			free(temp);
			}
		word[count]=c;
		count++;
		}
		/**
	*if we reached the end of a word
	**/	
		if(c == EOF || (c == ' ' || c =='\n' || c =='\t' || c =='\0') ){
			word[count]='\0';
			if(word[0] !=' ' && count >= 1){
				insert(&source,word);
				}
			count=0;
			}
		if(EOF == c) tst=1;
		c = getchar();
		}
	if(upsideDown) {
		printDown(&source,word,0);
	}
	else {
		printUp(&source,word,0);
	}
	freeTrie(&source);
	free(word);
return 0;
}
