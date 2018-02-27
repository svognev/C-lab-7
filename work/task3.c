#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"

int compare(const void *a, const void *b)
{
	if (((SSYM*)a)->freq < ((SSYM*)b)->freq)
		return 1;
	else
		return -1;
}

void lineSort(SSYM *arr, int size)
{
	qsort(arr, size, sizeof(SSYM), compare);
}

void clearStruct(SSYM *arr)
{
	for (int i = 0; i < SYM_NUM; i++)
	{
		arr[i].ch = i;
		arr[i].freq = 0.0f;
	}
}

void fillStruct(FILE *fp, SSYM *arr)
{
	int ch;
	int tmpArr[SYM_NUM] = { 0 };
	unsigned int countBtInit = 0;
	rewind(fp);

	while ((ch = fgetc(fp)) != EOF)
	{
		arr[(unsigned int)ch].freq++;
		tmpArr[(unsigned int)ch]++;
		countBtInit++;
	}

	int sum = 0;
	for (int i = 0; i < SYM_NUM; i++)
	{
		sum += tmpArr[i];
		arr[i].freq = ((float)tmpArr[i]) / countBtInit;
	}

	lineSort(arr, SYM_NUM);
}

void print(SSYM *arr)
{
	for (int i = 0; i < SYM_NUM; i++)
	{
		if (arr[i].freq > 0)
			printf("'%c' - %f\n", arr[i].ch, arr[i].freq);
	}
}