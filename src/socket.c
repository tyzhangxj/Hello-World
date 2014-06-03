#include "../include/socket.h"
void handle_client(void *fd)
{
	int recbytes;
	int *param = (int*)fd;
	int nfp = *param;
	printf("new_fd=%d\r\n",nfp);
	char buffer[1024] = {0};
	while(1)
	{
		if(-1 == (recbytes = read(nfp, buffer, 1024)))
		{
			return -1;
		}
		buffer[recbytes] = '\0';
		printf("%d thread receive:%s\r\n",nfp,buffer);
	}
	close(nfp);
}

int server_start(int sock)
{
	int sfp,nfp,sin_size;
	struct sockaddr_in s_add, c_add;
	unsigned short port = 8888;
	pthread_t id;
	
	//1. create
	sfp = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sfp)return -1;
	bzero(&s_add, sizeof(struct sockaddr_in));

	//2. bind
	s_add.sin_family = AF_INET;
	s_add.sin_addr.s_addr = htonl(INADDR_ANY);
	s_add.sin_port = htons(port);
	if(-1 == bind(sfp, (struct sockaddr*)(&s_add), sizeof(struct sockaddr)))return -1;

	//3. listen
	if(-1 == listen(sfp, 5))return -1;
	while(1)
	{
		//4. accept
		sin_size = sizeof(struct sockaddr_in);
		nfp = accept(sfp, (struct sockaddr*)(&c_add), &sin_size);
		if(-1 == nfp)return -1;
	
		//5. write
		if(-1 == write(nfp, "hello , welcome to my server \r\n",32))return -1;
		if( pthread_create(&id, NULL, (void*)handle_client, &nfp) == -1)
		{
			close(nfp);
			return -1;
		}
	}
	close(sfp);
	return 0;
}
