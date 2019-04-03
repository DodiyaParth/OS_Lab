#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
void main()
{
    pid_t main_pid=getpid();
    fork();
    pid_t pid=getpid();
    int i;
    for(i=0;i<50;i++)
        printf("PID= %d i=%d\n",pid,i);
        
    wait();
    printf("Ending of pid=%d\n",pid);
    
    //printf("\n\nAfter terminating child processes\n");
    
    if(pid!=main_pid)
        exit(EXIT_SUCCESS);
    printf("Exit from child process pid=%d\n",pid);
    
}
