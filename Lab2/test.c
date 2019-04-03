#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void main()
{
    creat("Test00.txt",0777);
    chdir("./test");
    creat("Test01.txt",0777);
}
