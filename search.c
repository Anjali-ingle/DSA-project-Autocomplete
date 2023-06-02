#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trie.h"

#define N 8

char** search(TrieNode *root, char* prefix, char* word) {
	int i, length, j, k=0, falsePrefix;
	char temp[2] = {0}, after_prefix[100] = {0};
	char **options = malloc(N * sizeof(char*));
	length = strlen(prefix);
	temp[0] = prefix[0];												//temp has the first character of the prefix
	char array[25] = {0}, array_final[25] = {0}, wordFound[25] = {0};
	temp[1] = '\0';	
	strcpy(after_prefix, word);
	TrieNode *tempr = root;
	LeafNode *temp_leaf;
	for (i=0 ; i<N ; i++)
		options[i] = NULL;
	if (length > 0) {													
		if (root->child[temp[0] % 'a'] != NULL) {						//i find the node that has the first char of the prefix
			strcat(word, temp);					
			search(root->child[temp[0] % 'a'], prefix + 1, word);		//remove the first char of the prefix
		}																//and look the node for the next char
		else {
			return NULL;
		}																
	}
	else {	//reached the last node of the given prefix
		for (i=0 ; i<N ; i++) {
			j = 0;
			if (root->leaf_pointer[i] != NULL) {			//found the leaf 
				root = root->leaf_pointer[i]->parent;	//start searching its father
				while (root != tempr) { 					// go up until the last node of the prefix is found
					array[j] = root->value;				//save each char found in the array
					j++;
					root = root->parent;				//and move up
				}
				array[j] = '\0';
				k = 0;
				for (j=strlen(array)-1 ; j>=0 ; j--) {	//reverse the array
					array_final[k] = array[j];
					k++;
				}
				array_final[k] = '\0';
				strcpy(wordFound, word);				//concatenation of the prefix and the word
				strcat(wordFound, array_final);	
				options[i] = malloc(sizeof(strlen(wordFound)));
				strcpy(options[i], wordFound);
				array[0] = '\0';
				array_final[0] = '\0';
				wordFound[0] = '\0';
				memset(after_prefix, 0, sizeof(after_prefix));
			}
		
		}
		for (i=0 ; i<N ; i++)  //free memory for the strings array
			if (options[i] == NULL)
				free(options[i]);
		return options;
	}
	
																		
}



