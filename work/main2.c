#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

int main(int argc, char *argv[])
{
	int ch;
	PNODE root = NULL;
	FILE *fpW = NULL, *fpC = NULL;
	char buf[SIZE2] = { "\0" };;
	char buf1[SIZE2] = { "\0" };
	char buf2[SIZE2] = { "\0" };
	int i = 0;
	while (argv[1][i] != '\0' && argv[1][i] != '\n')
	{
		buf1[i] = argv[1][i];
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0' && argv[2][i] != '\n')
	{
		buf2[i] = argv[2][i];
		i++;
	}
	fpW = fopen(buf1, "rt");
	fpC = fopen(buf2, "rt");
	if ((fpW == NULL) || (fpC == NULL))
	{
		puts("File error");
		return -1;
	}

	char rootSel[SIZE2] = "if";
	root = makeTree(root, rootSel);
	int minLen, maxLen;
	minLen = maxLen = strlen(rootSel);

	while (fscanf(fpW, "%s", buf) == 1)
	{
		chomp(buf);
		if (strlen(buf) < minLen)
			minLen = strlen(buf);
		if (strlen(buf) > maxLen)
			maxLen = strlen(buf);
		if (strcmp(buf, rootSel) == 0)
			continue;
		else
			root = makeTree(root, buf);
	}

	while (fscanf(fpC, "%s", buf) == 1)
	{
		procOneLine(root, minLen, maxLen, buf);
	}
	fclose(fpW);
	fclose(fpC);

	printTree(root);
	return 0;
}