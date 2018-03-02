#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task2.h"

char* chomp(char*buf)
{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = '\0';
		return buf;
}

struct node *makeTree(struct node *root, char *add)
{
	
	if (root == NULL)
	{
		root = (struct node*)malloc(sizeof(struct node));
		strcpy(root->word, add);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, add)>0)
		root->left = makeTree(root->left, add);
	else if (strcmp(root->word, add)<0)
		root->right = makeTree(root->right, add);
	return root;
}
void searchTree(struct node *root, char *word)
{
	if (root != NULL)
	{
		if (strcmp(root->word, word)==0)
		{
			root->count++;
			return;
		}
		if (strcmp(root->word, word) > 0)
			searchTree(root->left, word);
		if (strcmp(root->word, word) < 0)
			searchTree(root->right, word);
	}
}
void printTree(struct node*root)
{
	if (root != NULL)		//слева направо ВАС
	{
		printTree(root->left);
		printf("%s - %d\n", root->word,root->count);
		printTree(root->right);
	}

	/*if (root != NULL)		//прямой порядок АВС
	{
		printf("%s\n", root->word);
		printTree(root->left);
		printTree(root->right);
	}

	if (root != NULL)		//снизу вверх ВСА
	{
		
		printTree(root->left);
		printTree(root->right);
		printf("%s\n", root->word);
	}*/		
}