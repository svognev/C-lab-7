#include <stdio.h>
#define SIZE 256
struct SYM
{
	unsigned char ch;
	float freq;
	char code[256];
	struct SYM *left;
	struct SYM *right;
};

struct SYM** mkPsyms(FILE *fp, int *N);
void print(struct SYM** arr, int N);
void sort(struct SYM** arr, int N);
