#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"


NODE* Create(char *s)
{
	NODE* root = (NODE*)malloc(sizeof(NODE));
	root->data = (char*)malloc(strlen(s) + 1);
	strcpy(root->data, s);
	root->brother = NULL;
	root->child = NULL;
	return root;
}

NODE* AddBrother(NODE* oldbrother, char* s, int size)
{
	NODE* p = oldbrother;
	while (p&& p->brother)
		p = p->brother;
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = (char*)malloc(strlen(s) + 1);
	strcpy(temp->data, s);
	temp->brother = NULL;
	temp->child = NULL;
	temp->size = size;
	if (p)
		p->brother = temp;
	else
		p = temp;
	return oldbrother;
}

NODE* AddChild(NODE * par, char * s, int size)
{
	if (par->child)
		par->child = AddBrother(par->child, s, size);
	else
	{
		par->child = (NODE*)malloc(sizeof(NODE));
		par->child->data = (char*)malloc(strlen(s) + 1);
		strcpy(par->child->data, s);
		par->child->size = size;
		par->child->child = NULL;
		par->child->brother = NULL;
	}
	return par;
}

void Print(NODE* root, int level, FILE *fout)
{
	NODE* p = root;
	for (int i = 0; i < level; i++)
		fprintf(fout, "   ");
	fprintf(fout, "%s\n", p->data);
	if (p->child)
		Print(p->child, level + 1, fout);
	if (p->brother)
		Print(p->brother, level, fout);
}


NODE* DelTree(NODE* root)
{
	NODE* p = root;
	if (p->brother)
		p->brother = DelTree(p->brother);
	if (p->child)
		p->child = DelTree(p->child);
	free(p->data);
	free(p);
	return NULL;
}

int Found(NODE* root, char *name)
{
	NODE* p = root;
	if (p->data == name)
	{
		if (p->brother)
			Found(p->brother, name);
		return 1;
	}
	else
	{
		if (p->child)
			if (Found(p->child, name))
				printf("%s\n", p->data);
		if (p->brother)
			if (Found(p->brother, name))
				return 1;
	}
	return 0;
}

int Count(Node *root)
{
	Node *p = root;
	int i = 0;
	if (p->child)
		i += Count(p->child);
	else
		i += 1;
	if (p->brother)
		i += Count(p->brother);
	return i;
}

void PrintA(NODE* root, int level, int size)
{
	NODE* p = root;
	if(p->size >= size){
		for (int i = 0; i < level; i++)
			printf("   ");
		printf("%s\n", p->data);
	}
	if (p->child)
		PrintA(p->child, level + 1, size);
	if (p->brother)
		PrintA(p->brother, level, size);
}
