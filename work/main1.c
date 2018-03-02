#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "task1.h"



int main()
{
	struct CRN *head=NULL;
	//struct CRN *ptrList;
	FILE *fp = fopen("fips10_4.csv", "rt");
	if (fp == NULL)
	{
		printf("FIle is not openning!");
		return 0;
	}
	head=mkList(fp);
	//printList(head);
	findName("Harare", head);
	findCountry("RU", head);
	fclose(fp);
	
	return 0;
}