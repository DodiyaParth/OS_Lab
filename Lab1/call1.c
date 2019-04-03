#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
void main()
{
	int fd=creat("Hello.txt",777);
	printf("fd=%d\n",fd);
	//printf("%d\n",S_WGRP);
}

//rwxrwxrwx
