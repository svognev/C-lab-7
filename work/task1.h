#define SIZE1 512

struct REGION_DATA
{
	char abreviatura[3];
	char number[3];
	char name[50];
};

typedef struct REGION_DATA REGION;
typedef REGION* PREGION;

struct ITEM
{
	PREGION region_data;
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM TITEM;
typedef TITEM* PITEM;

PITEM createList(PREGION region_data);
PREGION createName(char *Line);
PITEM addToTail(PITEM tail, PREGION region_data);
int countList(PITEM head);
PITEM findByAbr(PITEM head, char *abreviatura);
PITEM findByName(PITEM head, char *name);
void printName(PITEM item);
int checkStr(PREGION strP);