#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE2 256

struct NODE
{
	unsigned long count;
	char word[SIZE2];
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE TNODE;
typedef TNODE* PNODE;

PNODE makeTree(PNODE root, char *word);
int searchTree(PNODE root, char *words);
char* chomp(char *buf);
int isApprLett(char sym);
char* cleanBuf(char *buf);
void findWords(char *in, char(*words)[SIZE2]);
void procOneLine(PNODE root, int minLen, int maxLen, char *buf);
void clearWords(char(*words)[SIZE2]);
void printTree(PNODE root);
