#include<stdio.h>
#include<semaphore.h>
#include<unistd.h>
#include<pthread.h>
#define n 5
#define left (l-1)%n
#define right (l+1)%n

sem_t cs[n];

void* philosopher(void* i)
{
	long l=(long)i;
	while(1)
	{
		printf("Philosopher %ld is THINKING\n",l);
		sleep(1);
		printf("Philosopher %ld is HUNGRY\n",l);
		sleep(1);	
		sem_wait(&cs[left]);
		sem_wait(&cs[right]);
		printf("Philosopher %ld is EATING with chopstik %ld and %ld\n",l,left,right);
		sleep(1);
		sem_post(&cs[left]);
		sem_post(&cs[right]);
	}
}

void main()
{
	int i;
	for(i=0;i<n;i++)
	{
		sem_init(&cs[i],0,1);
	}
	pthread_t phil[n];
	for(i=0;i<n;i++)
	{
		pthread_create(&phil[i],NULL,philosopher,(void*)(long)i);
	}
	for(i=0;i<n;i++)
	{
		pthread_join(phil[i],NULL);
	}
}
