#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "trie.h"

#define N 8

int main(int argc, char* argv[]) {
	int j;
	TrieNode *root;
	root = malloc(sizeof(TrieNode));
	char temp[2] = {0}, bla[10] = {0}, *path;
	for (j=0 ; j<26 ; j++) 
				root->child[j] = 0;	

	if (argc > 1) {
		if (strcmp(argv[1], "-d") == 0) {
			root = readFile(root, argv[2]);
			get_input(root, argv[2]);
		}
	}
	else {
		path = getenv("HOME");		//find the home folder
		strcat(path, "/words");
		printf("%s\n", path);
		root = readFile(root, path);
		get_input(root, path);
	}
	//execl("/usr/bin/sort", "usr/bin/sort", "-d", path, "test.txt", (char*)NULL);
	//execlp("sort","sort","-d", path,"words",NULL);
	freeTrieNodes(root);		
}

void freeTrieNodes(TrieNode *root) {
	int i;
	for (i=0 ; i<26 ; i++) {
		if (root->child[i] != NULL)
			freeTrieNodes(root->child[i]);
	}
	free(root->leaf);
	
	free(root);

}
