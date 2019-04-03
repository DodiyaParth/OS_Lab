#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int ind=-1;
void wait()
{
    mutex--;
}

void post()
{
    mutex++;
}

void main()
{
    int i;
    while(1)
    {
        printf("Enter choice\n1. Writer enter   2. Reader Enter   3. Writer Exit   4. Reader exit  5. exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                if(mutex==1)
                {
                    printf("Writer enters into critical section\n");
                    wait();
                    ind=0;
                }else
                {
                    printf("cannot enter in the critical section\n");
                }
                break;
             case 2:
                if(mutex==1)
                {
                    printf("Reader enters into critical section\n");
                    wait();
                    ind=1;
                }else
                {
                    printf("cannot enter in the critical section\n");
                }
                break;
             case 3:
                if(mutex==0)
                {
                    if(ind==0)
                    {
                        printf("Writer exits from critical section\n");
                        post();
                        ind=-1;
                    }
                    else if(ind==1){
                        printf("Reader is in the critical section\n");
                    }   
                }else
                {
                    printf("Critical section is empty\n");
                }
                break;
             case 4:
                if(mutex==0)
                {
                    if(ind==1)
                    {
                        printf("Reader exits from critical section\n");
                        post();
                        ind=-1;
                    }
                    else if(ind==0){
                        printf("Writer is in the critical section\n");
                    } 
                    
                }else
                {
                    printf("Critical section is empty\n");
                
                }
                break;
             case 5:
                return;
                break;
                default:
                    printf("Enter valid choice\n");  
              
        }
    }
}

