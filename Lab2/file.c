#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
void main()
{
    int fd=open("hello.txt",O_WRONLY);
       printf("FD= %d\n",fd);
       if(fd==-1)
            return;
    printf("Lseek from at 50th charecter from last\n");
    lseek(fd,25,SEEK_SET);
    char buff[100];
    int count=read(fd,buff,55);
    buff[count]='\0';
    printf("\n%s\n",buff);
    printf("Creating new fd\n");
    int nfd=dup(fd);
    printf("New fd=%d\n",nfd);
    chdir("./lab1");
}
