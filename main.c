#include <stdio.h>
#include <pthread.h>
#include "include/parse.h"
#include "include/link.h"
#include "include/socket.h"
void thread()
{
    int i;
    for(i = 0 ; i < 3 ; i++ )
    {
	sleep(1);
	printf("this is a pthread.\n");
    }
}

int main(int argc,char **argv)
{
    parse_input(argc,argv);

    //link list
    Link head = NULL;
    Link New;
    head = create_list(head);
    print_list(head);
    free_list(head);

    //thread
    pthread_t id;
    int ret;
    ret = pthread_create(&id,NULL,(void *)thread,NULL);
    if(ret !=0 )
    {
	printf("create pthread error!\n");
	exit(1);
    }
    pthread_join(id,NULL);
    printf("Hello World !\n");

    //socket
    server_start(8888);
    return 0;
 }
