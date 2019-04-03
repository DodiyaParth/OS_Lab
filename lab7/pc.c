#include<stdio.h>
#include<stdlib.h>
#define N 5
int i=-1;
int mutex=1;
int buffer[N];
int fill=0;
int empty=N;

void wait(int *n)
{
    *n=*n-1;
}

void post(int* n)
{
    *n=*n+1;
}

void produce()
{
    if(empty==0)
    {
        printf("buffer is full");
        return;
    }
    wait(&empty);
    buffer[++i]=rand()%5;
    printf("Produced %d\n",buffer[i]);
    post(&fill);
}

void consume()
{
    if(fill==0)
    {
        printf("buffer is empty");
        return;
    }
    wait(&fill);
    printf("User consumed %d\n",buffer[i--]);
    post(&empty);
}

void main()
{
    int i;
    while(1)
    {
        printf("Enter choice\n1. Produce  2. Consume  0.Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                produce();
                break;
            case 2:
                consume();
                break;
            case 0:
                return;
                break;
            default:
                printf("Enter valid choice\n");    
        }
    }
}










