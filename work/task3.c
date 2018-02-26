#include "task3.h"
#include <stdlib.h>


struct SYM** mkPsyms(FILE *fp,int *N)
{
	struct SYM* syms;
	struct SYM** psyms;
	int count = 0, i = 0, j = 0;
	int ch=0;
	syms = (struct SYM*)calloc(SIZE, sizeof(struct SYM)); //создаем массив структур
	for (i = 0; i < SIZE; i++)								//обнуляем
	{
		syms[i].ch = i;
		syms[i].freq = 0;
		syms[i].code[0] = 0;
		syms[i].left = NULL;
		syms[i].right = NULL;
	}
	while ((ch = fgetc(fp)) != EOF)									//анализ файла, подсчет общего колва символов, заполнение массива структур количеством символов
	{
		count++;
		syms[ch].freq++;
	}
	for (i = 0; i < SIZE; i++)							//считаем частоту в долях + определяем количество заполненных структур
	{
		if (syms[i].freq != 0)
		{
			(*N)++;
			syms[i].freq = syms[i].freq / count;
		}	
	}
	psyms = (struct SYM**)calloc(sizeof(struct SYM*), *N);	//создаем массив указателей на ненулевые структуры
	for (i = 0; i < SIZE; i++)
	{
		if (syms[i].freq != 0)
			psyms[j++] = syms + i;
	}

	sort(psyms,*N);
	return psyms;
}

void print(struct SYM** arr,int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%c - %f\n", arr[i]->ch, arr[i]->freq);
	}
}

void sort(struct SYM** arr,int N)
{
	struct SYM* temp;
	int i = 0, j = 0;
	for (i = 0; i < N;i++)
	for (j = N-1; j > i; j--)
	{
		if (arr[i]->freq < arr[j]->freq)
		{
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}
