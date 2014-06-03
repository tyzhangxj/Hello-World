#include "../include/link.h"
Link create_list(Link head)
{
	int Data;
	char a[10];
	//a = "abc";
	Link New;
	Link Pointer;
	head = (Link)malloc(sizeof(Node));
	if(head == NULL)
		printf("can not create link head !\n");
	else
	{
		Data = 1;
		head->data = Data;
		head->next = NULL;
	}
	Pointer = head;
	while(Data<=10)
	{
		Data++;
		New = (Link)malloc(sizeof(Node));
		New->data = Data;
		New->content[0] = 'a';
		New->next = NULL;
		Pointer->next = New;
		Pointer = New;
	}
	return head;
}

void print_list(Link head)
{
	Link Pointer;
	Pointer = head;
	printf("List is :\n");
	while(Pointer != NULL)
	{	
		printf("=>%d:%s;\n",Pointer->data,Pointer->content);
		Pointer = Pointer->next;
	}
	printf("\n");
}
void free_list(Link head)
{
	Link Pointer;
	while(head!=NULL)
	{
		Pointer = head;
		head = head->next;
		free(Pointer);
	}
}

