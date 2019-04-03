#include<stdio.h>
#include<stdlib.h>
typedef struct proc{
    int pid,prio,at,bt,ct,tat,wt;
}proc;
proc* pr;
int* boola;
int n,counter;
int pop(int t)
{
	int i,max=-1000,mi=-1;
	for(i=0;i<n;i++)
	{
		if(pr[i].at<=t && boola[i]==0)
		{
			if(pr[i].prio>max)
			{
				mi=i;
				max=pr[i].prio;
			}
		}
	}
	return mi;
}

int minproc(int t)
{
	int i,min=10000;
	for(i=0;i<n;i++)
	{
		if(pr[i].at<min && boola[i]==0)
		{
			min=pr[i].at;
		}
	}
	return min;
}

void main()
{
    int i,ttat=0,twt=0;
    printf("Enter how many proccess you want to enter,\n");
    scanf("%d",&n);
    pr=malloc(n*sizeof(proc));
    boola=malloc(n*4);
    counter=n;
    for(i=0;i<n;i++)
    	boola[i]=0;
    printf("priority is higher when number is big\n");
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time, burst time and priority for process %d\n",i+1);
        scanf("%d %d %d",&pr[i].at,&pr[i].bt,&pr[i].prio);
        pr[i].pid=i+1;
    }
    int t=0,pi;
    printf("\n\n");
    while(counter>0)
    {
    	pi=pop(t);
    	if(pi==-1)
    	{
    		int c=minproc(t);
    		printf("%d - %d : CPU Idle\n",t,c);
    		t=c;
    	}
    	else
    	{
    		//printf("%d\n",t );
    		boola[pi]=1;
    		pr[pi].ct=t+pr[pi].bt;
    		printf("%d - %d : Process %d\n",t,pr[pi].ct,pr[pi].pid);
    		t=pr[pi].ct;
    		counter--;
    		pr[pi].tat=pr[pi].ct-pr[pi].at;
    		pr[pi].wt=pr[pi].tat-pr[pi].bt;
    		ttat+=pr[pi].tat;
    		twt+=pr[pi].wt;
    	}
    }
    printf("\n    AT  Bt  CT  TAT  WT\n");
    for(i=0;i<n;i++)
        printf("p%d  %d    %d   %d   %d   %d\n",pr[i].pid,pr[i].at,pr[i].bt,pr[i].ct,pr[i].tat,pr[i].wt);
    printf("\nAWT=%f  ATAT=%f\n\n\n",(twt*1.0)/n,(ttat*1.0)/n);
}
