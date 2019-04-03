#include<stdio.h>
#include<stdlib.h>
typedef struct proc{
    int pid,at,bt,ct,tat,wt;
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
        pr[i].pid=i+1;
    }
    int t=0;
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
    int* boola=malloc(n*4);
    for(i=0;i<n;i++)
        boola[i]=0;
    t=pr[0].at+pr[0].bt;
    pr[0].ct=t;
    pr[0].tat=pr[0].ct-pr[0].at;
    pr[0].wt=pr[0].tat-pr[0].bt;
    if(pr[0].at>0)
        printf("CPU Idle interval: %d-%d\n",0,pr[0].at);
    int id,flag,max;
    boola[0]=1;
    int twt=pr[0].wt,ttat=pr[0].tat;
    for(j=0;j<n;j++)
    {
        flag=0;
        max=1000;
        for(i=0;i<n;i++)
        {
            if(boola[i]==0&&pr[i].at<=t&&pr[i].bt<max)
            {
                max=pr[i].bt;
                flag=1;
                id=i;
            }
        }
        if(flag==0)
        {
            int k=0;
            while(boola[k]!=0&&k<n)
                k++;    
            id=k;
            printf("CPU Idle interval: %d-%d\n",t,pr[id].at);
            t=pr[id].at;
        }
        //printf("id=%d\n",id);
        boola[id]=1;
        i=id;
        pr[i].ct=t+pr[i].bt;
        pr[i].tat=pr[i].ct-pr[i].at;
        t=pr[i].ct;
        pr[i].wt=pr[i].tat-pr[i].bt;
        twt+=pr[i].wt;
        ttat+=pr[i].tat;
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
    printf("\n");
    printf("    AT  Bt  CT  TAT  WT\n");
    for(i=0;i<n;i++)
        printf("p%d  %d    %d   %d   %d   %d\n",pr[i].pid,pr[i].at,pr[i].bt,pr[i].ct,pr[i].tat,pr[i].wt);
    printf("\nAWT=%f  ATAT=%f\n",(twt*1.0)/n,(ttat*1.0)/n);
}
