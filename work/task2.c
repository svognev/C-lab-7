#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

PNODE makeTree(PNODE root, char *word)
{
	if (root == NULL)
	{
		root = (PNODE)malloc(sizeof(TNODE));
		strcpy(root->word, word);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, word)>0)
		root->left = makeTree(root->left, word);
	else if (strcmp(root->word, word)<0)
		root->right = makeTree(root->right, word);
	else
		root->count++;
	return root;
}

int searchTree(PNODE root, char *words)
{
	if (root == NULL)
		return 0;

	if (strcmp(root->word, words) > 0)
		return searchTree(root->left, words);
	else if (strcmp(root->word, words) < 0)
		return searchTree(root->right, words);
	else if (strcmp(root->word, words) == 0)
	{
		root->count++;
		return 1;
	}
	return 0;
}

char* chomp(char *buf)
{
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	return buf;
}

int isApprLett(char sym)
{
	return (sym >= 'a') && (sym <= 'z');
}

char* cleanBuf(char *buf)
{
	int i = 0;
	while (buf[i])
	{
		if (!isApprLett(buf[i]) && (buf[i] != ' '))
			buf[i] = ' ';
		i++;
	}
	return buf;
}

void findWords(char *in, char(*words)[SIZE2])
{
	int i = 0, inWord = 0, count = 0, k = 0;
	while (in[i])
	{
		if (in[i] != ' ' && inWord == 0)
		{
			inWord = 1;
			words[count][k] = in[i];
			k++;
			if (in[i + 1] == '\0')
			{
				words[count][k] = '\0';
				inWord = 0;
				count++;
				k = 0;
				break;
			}
		}
		else if (in[i] == ' ' && inWord == 1)
		{
			words[count][k] = '\0';
			inWord = 0;
			count++;
			k = 0;
		}
		else if (in[i] != ' ' && inWord == 1)
		{
			words[count][k] = in[i];
			k++;
			if (in[i + 1] == '\0')
			{
				words[count][k] = '\0';
				inWord = 0;
				count++;
				k = 0;
				break;
			}
		}
		i++;
	}
}

void procOneLine(PNODE root, int minLen, int maxLen, char *buf)
{
	int currLen = 0;
	char words[SIZE2][SIZE2] = { '\0' };
	clearWords(words);
	chomp(buf);
	cleanBuf(buf);
	findWords(buf, words);

	for (int i = 0; i < SIZE2; i++)
	{
		currLen = strlen(words[i]);
		if ((currLen >= minLen) && (currLen <= maxLen))
			searchTree(root, words[i]);
	}

	for (int i = 0; i < SIZE2; i++)
		buf[i] = '\0';
}

void clearWords(char(*words)[SIZE2])
{
	int i = 0, j = 0;
	for (i = 0; i < SIZE2; i++)
	{
		for (j = 0; j < SIZE2; j++)
			words[i][j] = '\0';
	}
}

void printTree(PNODE root)
{
	if (root->left)
		printTree(root->left);
	printf("%s - %lu\n", root->word, root->count);
	if (root->right)
		printTree(root->right);
}
