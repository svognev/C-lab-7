#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task3.h"


int main(int argc, char* argv[])
{
	struct SYM** psyms = 0;
	int N = 0;
	if (argc > 1)
	{
		FILE *fp = fopen(argv[1], "rt");
	}
	FILE *fp = fopen("keywords.txt", "rt");
	if (fp == NULL)
		{
			printf("File is not openning");
			return 1;
		}
	psyms = mkPsyms(fp, &N);
	print(psyms, N);
	if (fclose(fp) == EOF)
	{
		printf("Error! Can`t close file!!");
	}
	return 0;
}