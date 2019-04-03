#include<stdio.h> 
#include<signal.h> 
  
void handle_sigint(int sig) 
{ 
    printf("Caught signal %d\n", sig); 
} 
  
int main() 
{ 
    signal(SIGINT, handle_sigint);  
    while(1)
    {
        printf("Hello world\n");
        sleep(2);
    }
    return 0; 
} 
