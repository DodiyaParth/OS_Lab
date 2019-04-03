#include<stdio.h>
#include<stdlib.h>
typedef struct proc{
    int pid,at,bt,ct,tat,wt;
}proc;

void main()
{
    int n,i;
    printf("Enter how many proccess you want to enter,\n");
    scanf("%d",&n);
    proc* pr=malloc(n*sizeof(proc));
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time and burst time for process %d\n",i+1);
        scanf("%d %d",&pr[i].at,&pr[i].bt);
        pr[i].pid=i+1;
    }
    int j;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n-1;i++)
        {
            if(pr[i].at>pr[i+1].at||(pr[i].at==pr[i+1].at&&pr[i].bt>pr[i+1].bt))
            {
                proc temp=pr[i];
                pr[i]=pr[i+1];
                pr[i+1]=temp;
            }
        }
    }
    printf("\n");
    int ttat=0,twt=0,t=0;
    for(i=0;i<n;i++)
    {
        if(pr[i].at>t)
        {
            printf("CPU Idle interval: %d - %d\n",t,pr[i].at);
            t=pr[i].at;
        }
        if(i==0)
        {
            pr[i].ct=pr[i].at+pr[i].bt;
            t=pr[i].ct;
        }
        else
        {
            pr[i].ct=t+pr[i].bt;
            t=pr[i].ct;
            
        }
        pr[i].tat=pr[i].ct-pr[i].at;
        pr[i].wt=pr[i].tat-pr[i].bt;
        ttat+=pr[i].tat;
        twt+=pr[i].wt;
    }
    printf("\n");
    for(j=0;j<n;j++)
    {
        for(i=0;i<n-1;i++)
        {
            if(pr[i].pid>pr[i+1].pid)
            {
                proc t=pr[i];
                pr[i]=pr[i+1];
                pr[i+1]=t;
            }
        }
    }
    printf("    AT  Bt  CT  TAT  WT\n");
    for(i=0;i<n;i++)
        printf("p%d  %d    %d   %d   %d   %d\n",pr[i].pid,pr[i].at,pr[i].bt,pr[i].ct,pr[i].tat,pr[i].wt);
    printf("\nAWT=%f  ATAT=%f\n",(twt*1.0)/n,(ttat*1.0)/n);
}


















