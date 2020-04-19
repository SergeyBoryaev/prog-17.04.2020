#ifndef TREE_H
#define TREE_H

typedef struct Node
{
	char* data;
	int size;
	struct Node* child;
	struct Node* brother;
}NODE;

NODE* Create(char *s);
NODE* AddBrother(NODE* oldbrother, char* s, int size);
NODE* AddChild(NODE * par, char * s, int size);
void Print(NODE* root, int level, FILE *fout);
NODE* DelTree(NODE* root);
int Found(NODE* root, char *name);
int Count(Node *root);
void PrintA(NODE* root, int level, int size);

#endif // !TREE_H