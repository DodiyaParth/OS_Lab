
#include<stdio.h>
#include<stdlib.h>

int n,cylinderSize,prevRead,iniPos,count,seekTime;
int* input;
int* flag;

int dis(int a,int b)
{
    return a-b>0?a-b:b-a;
}

void sstf();

void main()
{
    printf("Enter Cylinder Size\n");
    scanf("%d",&cylinderSize);
    //printf("Enter Previous Header position\n");
    //scanf("%d",&prevRead);
    printf("Current Header position\n");
    scanf("%d",&iniPos);
    printf("Enter the number of inputs\n");
    scanf("%d",&n);
    count=n;
    seekTime=0;
    input=malloc(4*n);
    flag=malloc(4*n);
    int i;
    printf("Enter %d input in the range(%d, %d)\n",n,0,cylinderSize-1);
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        flag[i]=0;
    }
    sstf();
}

int near(int cur)
{
    int i;
    int* dist=malloc(4*n);
    int min=cylinderSize+100,ind;
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            dist[i]=dis(cur,input[i]);
            if(dist[i]<min)
            {
                min=dist[i];
                ind=i;
            }        
        }else{
            dist[i]=n+100;
        }
    }    
    return ind;
}

void sstf()
{
    int cur=iniPos;
    printf("\nSequence: ");
    while(count>0)
    {
        int ind=near(cur);
        printf("%d ->",input[ind]);
        seekTime+=dis(input[ind],cur);
        cur=input[ind];
        flag[ind]=1;
        count--;
    }
    printf("\nSeekTime: %d\n",seekTime);
}









