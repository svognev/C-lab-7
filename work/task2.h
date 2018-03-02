char* chomp(char*buf);
struct node *makeTree(struct node *root, char *add);
void searchTree(struct node *root, char *word);
void printTree(struct node*root);

struct node
{
	char word[256];
	unsigned int count;
	struct node *left;
	struct node *right;
};