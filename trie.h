
#define N 8

typedef struct Node {
	char value;
	struct Node *child[26];
	struct Node *parent;
	struct Leaf *leaf;
	struct Leaf *leaf_pointer[N];
} TrieNode;

typedef struct Leaf {
	int counter;
	struct Node *parent;
} LeafNode;

TrieNode* readFile(TrieNode*, char*);
TrieNode* addToTrie(TrieNode*, char*);
char** search(TrieNode*, char*, char*);
char** sort(char**);
void update(TrieNode*, char*, LeafNode*);
void freeMem(TrieNode*);
void freeTrieNodes(TrieNode*);
int get_input(TrieNode*, char*);
int getchar_silent();
void increaseCounter(TrieNode *, char*, int);
int searchWord(TrieNode*, char*);
void addToDict(char*, char*);
