#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trie.h"

#define N 8


void update(TrieNode *root, char *word, LeafNode *leaf) {
	int i, j, pos, found, same_leaf = 0, value = 0;
	char after_prefix[100] = {0}, temp[2]={0};
	TrieNode *temp_root = root;
	LeafNode *leaf_found;

	found = 0;
	for (j=0 ; j<N ; j++) {
		if (temp_root->leaf_pointer[j] != NULL) {				//if there is a leaf in this position
			if (temp_root->leaf_pointer[j] == leaf) {			
				same_leaf = 1;									//flag that i found the same leaf so there is no reason to change it
			}
			else {
					if (temp_root->leaf_pointer[j]->counter < leaf->counter) { //if the leaf is different
						if (temp_root->leaf_pointer[j]->counter <= value) {		//compare with the previous position
							pos = j;
							value = temp_root->leaf_pointer[j]->counter;	
							found = 1;
						}
					}
			}
		}
			
	}
	if (same_leaf != 1 && found == 1) //so add the leaf in the node's array
		temp_root->leaf_pointer[pos] = leaf;
}

void increaseCounter(TrieNode *root, char* word, int new) {
	int i, length, cell;
	if (new == 0) 					//new word without \n
		length = strlen(word);
	else //with \n
		length = strlen(word) - 1; //existing word 
	TrieNode *temp = root;
	char s[2] = {0};
	char temp_word[26] = {0};

	for (i=0 ; i<length  ; i++) {					//find the leaf	
		cell = word[i] % 'a';						//to increase its counter
		root = root->child[cell];					
	}

	root->leaf->counter++;

	for (i=0 ; i<length ; i++) {				//every time i attach the next char of the word
		s[0] = word[i];							//and search the array of that node
		s[1] = '\0';
		strcat(temp_word, s);
		temp = temp->child[word[i] % 'a'];
		update(temp, temp_word, root->leaf);
	}
}

/*search if word exists in trie*/
int searchWord(TrieNode *root, char *word) {
	int i, cell, found = 0;
	int length = strlen(word) - 1;
	for (i=0 ; i<length ; i++) {	//i search for every char of the given word
		cell = word[i] % 'a';		//using the ascii code
		
		if (root->child[cell] != NULL) { 
			root = root->child[cell]; 
		}
		else { 			//if there is no other child, i didn't find the wrod
			found = 0;
			break;
		}
		if (i == length -1) {			//if i search for the last char
			if (root->leaf != NULL)		//and the char node has a leaf,
				found = 1;				// i found the word in the trie
			else
				found = 0;
		}
		
	}
	return found;	
}
