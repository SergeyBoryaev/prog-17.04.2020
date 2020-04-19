#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <io.h>
#include "tree.h"
#include "catalog.h"

NODE *Go(char *path, NODE *root, int size)
{
	struct _finddata_t fc;
	intptr_t hFile = _findfirst(path, &fc);
	if (!hFile)
		return root;
	_findnext(hFile, &fc);
	while (_findnext(hFile, &fc) == 0)
	{
		if (fc.attrib & _A_SUBDIR)
		{
			root = AddChild(root, fc.name, fc.size);
			char path1[1000];
			strcpy(path1, path);
			strcpy(path1 + strlen(path1) - 1, fc.name);
			strcat(path1, "\\*");
			NODE *p = root->child;
			while (p->brother)
				p = p->brother;
			p = Go(path1, p);
		}
		else
			root = AddChild(root, fc.name, fc.size);
	}
	return root;
}

NODE *MakeTree(char *path, NODE *root, int size)
{
	strcat(path, "\\*");
	root = Go(path, root, size);
	return root;
}
