
#define SYM_NUM 256
#define BT_SIZE 8

struct SYM // представление символа
{
	unsigned char ch;   // ASCII-код
	float freq;         // частота
};

typedef struct SYM SSYM;

int compare(const void *a, const void *b);
void lineSort(SSYM *arr, int size);
void clearStruct(SSYM *arr);
void fillStruct(FILE *fp, SSYM *arr);
void print(SSYM *arr);