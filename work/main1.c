#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

int main()
{
	FILE* fp;
	int count = 0;
	char buf[SIZE1] = { '\0' };
	PITEM head, tail, item;
	fp = fopen("fips10_4.csv", "rt");
	if (fp == NULL)
	{
		perror("File error.");
		return 1;
	}

	PREGION tmp;
	while (fgets(buf, SIZE1, fp))
	{
		tmp = createName(buf);
		if (!checkStr(tmp))
			continue;
		if (count == 0)
		{
			head = createList(tmp);
			tail = head;
		}
		else
		{
			tail = addToTail(tail, tmp);
		}
		count++;
	}

	fclose(fp);
	printf("Total items: %d\n", countList(head));

	item = findByAbr(head, "ZW");
	printName(item);
	putchar('\n');

	item = findByName(head, "Orientale");
	printName(item);

	return 0;
}