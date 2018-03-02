#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

int main(int argc, char *argv[])
{
	SSYM arr[SYM_NUM];
	FILE *fp = NULL;
	char buf1[256] = { "\0" };
	int i = 0;
	while (argv[1][i] != '\0' && argv[1][i] != '\n')
	{
		buf1[i] = argv[1][i];
		i++;
	}
	fp = fopen(buf1, "rt");
	if (fp == NULL)
	{
		puts("File error");
		return -1;
	}

	clearStruct(arr);
	fillStruct(fp, arr);
	print(arr);

	return 0;
}