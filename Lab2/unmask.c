#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
    umask(0077);
    open("unmask_test1.txt",O_CREAT,0777);
    open("unmask_test2.txt",O_CREAT,0773);
}
