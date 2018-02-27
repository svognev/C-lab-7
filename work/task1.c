#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

PITEM createList(PREGION region_data)
{
	PITEM item = (PITEM)malloc(sizeof(TITEM));
	item->region_data = region_data;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

PREGION createName(char *line)
{
	int i = 0;
	PREGION region = (PREGION)malloc(sizeof(REGION));
	while (*line && *line != ',')
	{
		region->abreviatura[i] = *line;
		i++;
		line++;
	}
	region->abreviatura[i] = '\0';
	line++;
	i = 0;
	while (*line && *line != ',')
	{
		region->number[i] = *line;
		i++;
		line++;
	}
	region->number[i] = '\0';
	i = 0;
	line += 2;
	while (*line)
	{
		region->name[i] = *line;
		i++;
		line++;
	}
	region->name[i - 2] = '\0';
	return region;
}

PITEM addToTail(PITEM tail, PREGION region_data)
{
	PITEM item = createList(region_data);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
	}
	return item;
}

int countList(PITEM head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

PITEM findByAbr(PITEM head, char *abreviatura)
{
	while (head)
	{
		if (strcmp(head->region_data->abreviatura, abreviatura) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}

PITEM findByName(PITEM head, char *name)
{
	while (head)
	{
		if (strcmp(head->region_data->name, name) == 0)
			return head;
		head = head->next;
	}
	return NULL;
}

void printName(PITEM item)
{
	if (item != NULL)
	{
		puts(item->region_data->abreviatura);
		puts(item->region_data->number);
		puts(item->region_data->name);
	}
}

int checkStr(PREGION strP)
{
	if (strlen(strP->abreviatura) != 2)
		return 0;
	if (strlen(strP->number) != 2)
		return 0;
	return 1;
}
