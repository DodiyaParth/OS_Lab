#include<stdio.h>
#include<stdlib.h>

int n,cylinderSize,prevRead,iniPos,count,seekTime;
int* input;
int* flag;

int dis(int a,int b)
{
    return a-b>0?a-b:b-a;
}


void main()
{
    printf("Enter Cylinder Size\n");
    scanf("%d",&cylinderSize);
    printf("Enter Previous Header position\n");
    scanf("%d",&prevRead);
    printf("Current Header position\n");
    scanf("%d",&iniPos);
    printf("Enter the number of inputs\n");
    scanf("%d",&n);
    count=n;
    seekTime=0;
    input=malloc(4*n);
    flag=malloc(4*n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        flag[i]=0;
    }
    sort();
    sstf();
}

void sort()
{
    int i,j;
    for(j=0;j<n;j++)
        for(i=0;i<n-1;i++)
            if(input[i]>input[i+1])
            {
                int t=input[i];
                input[i]=input[i+1];
                input[i]=t;
            }
}

int near(int cur)
{
    int i,j,m;
    for(i=0;i<n-1;i++)
    {
        if(input[i]<=cur&&input[i+1]>=cur)
        {
            m=i;
            break;
        }
    }
    for(i=m;i<n;i++)
        if(flag[i]==0)
        break;
    for(j=m;j>=0;j++)
        if(flag[j]==0)
        break;
    if(input[i]-input[m]>input[m]-input[j])
        return j;
    else
        return i;
}

void sstf()
{
    int cur=iniPos;
    printf("Sequence:");
    for(;count>0;)
    {
        int ind=near(cur);
        seekTime+=dis(input[ind],cur);
        flag[ind]=1;
        count--;
        printf(" %d ->",input[ind]);
        cur=input[ind];
    }    
    printf("\n\nTotal Seek time: %d\n",seekTime);
}


















