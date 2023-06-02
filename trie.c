#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "trie.h"

#define N 8

TrieNode* readFile(TrieNode *root, char *path) {
	FILE *file;
	char word[26];

	
	if ((file = fopen(path, "r")) == NULL) {		//anoigw to leksiko
		perror("source-file not found");
		return NULL;
	}
	while(fgets(word, 25, file) != NULL) {   //gia kathe leksi pou diavazw
		root = addToTrie(root, word);		//prosthetw ti leksi sto trie
	}
	fclose(file);

	return root;
}



TrieNode* addToTrie(TrieNode *root, char* word) {
	int i, j, cell, length;
	if (root == NULL)
		root = malloc(sizeof(TrieNode));

	length = strlen(word);
	TrieNode *temp_root;
	LeafNode *temp;
	
	temp_root = root;												//save the root node to return it
	for (i=0 ; i<length - 1 ; i++) {								//for every character
		cell = word[i] % 'a';										//i will allocate memory for child node
		if (root->child[cell] == NULL) {								//if the child node is null
			root->child[cell] = malloc(sizeof(TrieNode));
			root->child[cell]->value = word[i];						//save the char value
			for (j=0 ; j<26 ; j++) 
				root->child[cell]->child[j] = 0;			
			root->child[cell]->parent = root;						//connect child to its father
		}
									
		root = root->child[cell];									//and move on the the child node
	}
	cell = '@' % 'a';
	root->leaf = malloc(sizeof(LeafNode));							//allocate space for the leaf node
	root->leaf->counter = 0;				
	root->leaf->parent = root;										//connect the leaf to its father
	temp = root->leaf;						
		
	while (root != temp_root){										//until i reach the root
		for (i=0 ; i<N ; i++) {										// i add the leaf in the array of every node-father of the leaf
			if (root->leaf_pointer[i] == NULL) {						//if there is space
				root->leaf_pointer[i] = malloc(sizeof(LeafNode));
				root->leaf_pointer[i] = temp;
				break;
			}
		}
		root = root->parent;
	}

	return temp_root;
	
}





