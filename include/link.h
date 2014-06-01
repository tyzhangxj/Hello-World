#include <stdio.h>
#include <stdlib.h>

struct list
{
	int data;
	char content[10];
	struct list *next;
};
typedef struct list Node;
typedef Node *Link;
Link create_list(Link head);
void print_list(Link head);
