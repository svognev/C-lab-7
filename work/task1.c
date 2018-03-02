#include <stdio.h>
#include "task1.h"
#include <stdlib.h>
#include <string.h>

char* copySub(char *where, char *to)
{
	while (*where != ',' && *where != '\n' && *where != '\0')
	{
		if (*where == '\"')
		{
			*where++;
			continue;
		}
		*to++ = *where++;
	}
	*to = '\0';
	return where;
}


int checkLine(char *line)
{
	char tmp[256];
	char *p = line;
	p = copySub(p, tmp); //country
	if (strlen(tmp) != 2)
		return 0;
	p = copySub(p+1, tmp); //region
	if (strlen(tmp) != 2)
		return 0;
	return 1;
}

struct CRN* setStruct(char *line)
{
	struct CRN *item = (struct CRN*)malloc(sizeof(struct CRN));
	char *p = line;
	p = copySub(p, item->country);
	p = copySub(p + 1, item->region);
	p = copySub(p + 1, item->name);
	item->next = NULL;
	return item;
}


struct CRN* mkList(FILE *fp)//, struct CRN** ptrList)
{
	int number = 0;
	int count = 0;
	char buf[256];
	struct CRN* item=NULL;
	struct CRN* head=NULL;
	/*while (fgets(buf, 256, fp))
		count++;
	rewind(fp);
	*ptrList = (struct CRN*)calloc(count, sizeof(struct CRN*));*/
	fgets(buf, 256, fp);
	fgets(buf, 256, fp);
	if (checkLine(buf))
	{
		head=setStruct(buf);
	}
	item = head;
	while (fgets(buf, 256, fp))
	{
		if (checkLine(buf))
		{
			item->next=setStruct(buf);
			item = item->next;
		}
	}
	return head;
}

void printList(struct CRN* head)
{
	while (head->next)
	{
		printf("%s,%s,%s\n", head->country, head->region, head->name);
		head = head->next;
	}
	printf("%s,%s,%s\n", head->country, head->region, head->name);
}

void findName(char* name,struct CRN* head)
{
	int count = 0;
	while (head->next)
	{
		if (!strcmp(name, head->name))
		{
			printf("%s,%s,%s\n", head->country, head->region, head->name);
			count++;
		}
		head = head->next;
	}
	if (!strcmp(name, head->name))
	{
		printf("%s,%s,%s\n", head->country, head->region, head->name);
		count++;
	}
	if (!count)
		printf("Name didnt find!\n");
	putchar('\n');
}

void findCountry(char* name, struct CRN* head)
{
	int count = 0;
	while (head->next)
	{
		if (!strcmp(name, head->country))
		{
			printf("%s,%s,%s\n", head->country, head->region, head->name);
			count++;
		}
		head = head->next;
	}
	if (!strcmp(name, head->country))
	{
		printf("%s,%s,%s\n", head->country, head->region, head->name);
		count++;
	}
	if (!count)
		printf("Name didnt find!\n");
	putchar('\n');
}
