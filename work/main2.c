#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <stdio.h>


int main(int argc,char* argv[])
{
	char word[256];
	char* buf = 0;
	struct node* root=0;
	FILE *fp = fopen("keywords.txt", "rt");
	if (!fp)
	{
		printf("File is not openning!");
		return 1;
	}
	while (fgets(word, 256, fp))
	{
		buf = chomp(word);
		root=makeTree(root, buf);
	}
	//printTree(root);
	fclose(fp);
	FILE *fp2;
	if (argc > 1)
		fp2 = fopen(argv[1], "rt");
	
	fp2 = fopen("task2.c", "rt");
	if (!fp2)
	{
		printf("File is not openning!");
		return 1;
	}
	char ch = 0;
	int i = 0;
	while (ch!=EOF)
	{
		ch = fgetc(fp2);
		if (ch == '\t')
			continue;
		word[i] = ch;
		if (word[i] == ' ' || word[i] == '\n' || word[i] == '(' || word[i] == ';' || word[i]=='*')
		{
			word[i] = 0;
			searchTree(root, word);
			i = -1;
		}
		i++;
	}
	fclose(fp2);
	printTree(root);
	return 0;
}