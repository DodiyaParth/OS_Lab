#include <unistd.h>
#include <sys/types.h>
#include<stdio.h>
void main()
{
    printf("User id=%d\n",getuid());
    printf("effective User id=%d\n",geteuid());
    printf("group id=%d\n",getgid());
    printf("effective group id=%d\n",getegid());
    printf("process id=%d\n",getpid());
    printf("effective process id=%d\n",getppid());
}
