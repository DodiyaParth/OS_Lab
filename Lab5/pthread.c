#include<pthread.h>
#include<stdio.h>

pthread_t p1,p2,p3;

void *loop(void* r)
{
    int* ri=(int*)r;
    int num=*ri;
    int i;
    for(i=0;i<num;i++)
        printf("%d \n",i);
}

void main()
{
    int a=300,b=50,c=100;
    pthread_create(&p1,NULL,loop,&a);
    pthread_create(&p2,NULL,loop,&b);
    pthread_create(&p3,NULL,loop,&c);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    pthread_join(p3,NULL);
}
