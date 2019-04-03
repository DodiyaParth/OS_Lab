#include<stdio.h>
#include<stdlib.h>

int n,cylinderSize,prevRead,iniPos,count,seekTime;
int* input;
int* flag;

int dis(int a,int b)
{
    return a-b>0?a-b:b-a;
}
void sort();
void scan();

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
    printf("Enter inputs\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        flag[i]=0;
    }
    sort();
    if(prevRead<iniPos)
    {
        scan(1);
        printf("\nSeekTime: %d\n",2*cylinderSize-iniPos);
    }
    else
    {
        scan(2);
        printf("\nSeekTime: %d\n",cylinderSize+iniPos);        
    }
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
                input[i+1]=t;
            }
}

void scan(int flag)
{
    if(flag==1)
    {
        int i;
        int prev=iniPos;
        for(i=0;i<n;i++)
            if(input[i]>=prev)
            break;
        int cur=i;
        if(prev==input[cur])
            printf("Sequence: %d ->",prev);
        else
            printf("Sequence: %d -> %d ->",prev,input[cur]);
        for(i=cur+1;i<n;i++)
            printf(" %d ->",input[i]);
        if(input[n-1]!=cylinderSize-1)
            printf(" %d ->",cylinderSize-1);
        for(i=cur-1;i>=0;i--)
        {
            printf(" %d ->",input[i]);
        }
        if(input[0]!=0)
            printf(" 0 ->");
    }
    else
    {
        int i;
        for(i=0;i<n;i++)
            if(input[i]>iniPos)
                break;
        int cur=i-1;
        if(iniPos!=input[cur])
            printf("Sequence: %d ->",iniPos);
        else
            printf("Sequence: ");
        for(i=cur;i>=0;i--)
            printf(" %d ->",input[i]);
        if(input[0]!=0)
            printf(" 0 ->");
        for(i=cur+1;i<n;i++)
            printf(" %d ->",input[i]);
        if(input[n-1]!=cylinderSize-1)
            printf(" %d ->",cylinderSize-1);
        printf("\n");
    }
}
















