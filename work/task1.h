
struct CRN* mkList(FILE *fp);// , struct CRN** ptrList);
void printList(struct CRN* head);
void findName(char* name, struct CRN* head);
void findCountry(char* name, struct CRN* head);

struct CRN
{
	char country[3];
	char region[3];
	char name[30];
	struct CRN* next;
};

