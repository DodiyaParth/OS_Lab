#include<stdio.h> 
#include<signal.h> 
  
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
} 
  
int main() 
{ 
    signal(SIGALRM, handle_sigint);  
    while(1)
    {
        printf("Hello world\n");
        sleep(3);
        alarm(1);
    }
    return 0; 
} 
