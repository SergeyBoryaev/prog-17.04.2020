#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <io.h>
#include "tree.h"
#include "catalog.h"

int main(int  argc, char * argv[])
{
	if (argc < 4)
		return -1;
	FILE* fout;
	fout = fopen(argv[1], "w");
	NODE* root = NULL;
	char path[1000];
	char name[1000];
	strcpy(name, argv[3]);
	strcpy(path, argv[2]);
	root = Create(path);
	root = MakeTree(path, root, 1000000000);
	Print(root, 0, fout);
	Found(root, name); // 1 zadanie
	printf("%d", Count(root)); // 2 zadanie
	int size; // 3 zadanie
	scanf("%d", &size);
	PrintA(root,0,size);
	fclose(fout);
	root = DelTree(root);
	return 0;
}
