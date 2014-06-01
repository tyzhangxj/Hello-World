#include <stdio.h>
#include "include/parse.h"
#include "include/link.h"

int main(int argc,char **argv)
{
    parse_input(argc,argv);
    Link head = NULL;
    Link New;
    head = create_list(head);
    print_list(head);
    free_list(head);
    printf("Hello World !\n");
    return 0;
}
