void parse_input(int argc,char **argv)
{
	int i;
	i = 0;
	if(argc == 1)
		printf("please input option\n");
	for(i=0;i<argc;i++)
		printf("parse:%d ,content:%s;\n",i,argv[i]);
}
