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
    for(i=0;i<20;i++)
    {
        sleep(1);
        printf("PID= %d i=%d\n",pid,i);
        if(i==10)
             kill(pid, SIGINT); 
    }    
    
   
    
}
