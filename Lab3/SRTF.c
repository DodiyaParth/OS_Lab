#include<stdio.h>
#include<stdlib.h>
typedef struct proc{
    int pid,at,bt,ct,tat,wt,rt;
}proc;

void main()
{
    int n,i,j;
    printf("Enter how many proccess you want to enter,\n");
    scanf("%d",&n);
    proc* pr=malloc(n*sizeof(proc));
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time and burst time for process %d\n",i+1);
        scanf("%d %d",&pr[i].at,&pr[i].bt);
        pr[i].rt=pr[i].bt;
        pr[i].pid=i+1;
    }
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
    int* boola=malloc(n*4);
    
    for(i=0;i<n;i++)
        boola[i]=0;
    int t=0,rem=n,cur,flag=0,ttat=0,twt=0;
    while(rem!=0)
    {
        int min=1000;
        for(j=0;j<n;j++)
        {
            if(boola[j]==0&&pr[j].at<=t&&pr[j].rt<min)
            {
                if(flag==1)
                {
                    if(pr[j].rt<pr[cur].rt)
                        cur=j;
                }
                else
                {
                    cur=j;
                }
                flag=1;
            }
        }
        if(flag==0)
            printf("%d-%d proc: CPU Idle\n",t,t+1);
        else
            {
                printf("%d-%d proc: p%d\n",t,t+1,pr[cur].pid);
                pr[cur].rt--;
                if(pr[cur].rt==0)
                {
                    flag=0;
                    pr[cur].ct=t+1;
                    pr[cur].tat=pr[cur].ct-pr[cur].at;
                    pr[cur].wt=pr[cur].tat-pr[cur].bt;
                    rem--;
                    boola[cur]=1;
                    ttat+=pr[cur].tat;
                    twt+=pr[cur].wt;
                }
            }
        t++;
    }   
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
