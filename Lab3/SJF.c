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
    int* bool=malloc(n*4);
    for(i=0;i<n;i++)
        bool[i]=0;
    int t=0,j,flag,mbt,id,mat,ttat=0,twt=0;
    for(j=0;j<n;j++)
    {
        flag=0;
        mbt=10000;
        for(i=0;i<n;i++)
        {
            mat=10000;
            if(bool[i]==0&&pr[i].at<=t&&pr[i].bt<mbt)
            {
                flag=1;
                id=i;
                bool[i]=1;
            }
            if(bool[i]==0&&pr[i].at<mat)
                mat=pr[i].at;
        }
        if(flag==0)
        {
            t=mat;
            j--;
        }
        if(flag==1)
        {
        i=id;
        pr[i].ct=t+pr[i].bt;
        t=pr[i].ct;
        pr[i].tat=pr[i].ct-pr[i].at;
        pr[i].wt=pr[i].tat-pr[i].bt;
        ttat+=pr[i].tat;
        twt+=pr[i].wt;
        }
    }
    printf("    AT  Bt  CT  TAT  WT\n");
    for(i=0;i<n;i++)
        printf("p%d  %d    %d   %d   %d   %d\n",pr[i].pid,pr[i].at,pr[i].bt,pr[i].ct,pr[i].tat,pr[i].wt);
    printf("\nAWT=%f  ATAT=%f\n",(twt*1.0)/n,(ttat*1.0)/n);  
}
