#include<stdio.h>
#include<stdlib.h>

int N,B; //N: no of proc    B: no of blocks

int* proc;
int* blocks; 
int* flag;

void bestfit();
void firstfit();
void worstfit();

void main()
{
    printf("Enter number of processes\n");
    scanf("%d",&N);
    printf("Enter number of blocks\n");
    scanf("%d",&B);
    proc=malloc(4*N);
    blocks=malloc(4*B);
    flag=malloc(4*B);
    printf("Enter size of %d blocks\n",B);
    int i;
    for(i=0;i<B;i++)
        scanf("%d",&blocks[i]);
    printf("Enter size of %d processes\n",N);
    for(i=0;i<N;i++)
        scanf("%d",&proc[i]);
    bestfit();
    firstfit();
    worstfit();
}

int exfrag()
{
    int i,sum=0;
    for(i=0;i<B;i++)
    {
        if(flag[i]==0)
            sum+=blocks[i];
    }
    return sum;
}

int findworst(int i)
{
    int j,max=0,ind=-1;
    for(j=0;j<B;j++)
    {
        if(flag[j]==0&&blocks[j]>max&&blocks[j]>=proc[i])
        {
            max=blocks[j];
            ind=j;
        }
    }
    return ind;
}

int findbest(int i)
{
    int j,ind=-1,fit=100000;
    for(j=0;j<B;j++)
    {
        if(flag[j]==0&&blocks[j]>=proc[i]&&(blocks[j]-proc[i])<fit)
        {
            ind=j;
            fit=blocks[j]-proc[i];
        }
    }
    return ind;
}

void bestfit()
{
    printf("\n* * *  Best Fit  * * *\n");
    int i;
    for(i=0;i<B;i++)
        flag[i]=0;
    for(i=0;i<N;i++)
    {
        int blk=findbest(i);
        if(blk==-1)
        {
            printf("process no: %d  cannot be allocated  external fragmentation: %d\n",i+1,exfrag());
        }else
        {
            printf("process no: %d  allocated to block no: %d  space aquired: %d  internal fragmentation: %d\n",i+1,blk+1,proc[i],blocks[blk]-proc[i]);
            flag[blk]=1;
        }
    }
}

void worstfit()
{
    printf("\n* * *  Worst Fit  * * *\n");
    int i;
    for(i=0;i<B;i++)
        flag[i]=0;
    for(i=0;i<N;i++)
    {
        int blk=findworst(i);
        if(blk==-1)
        {
            printf("process no: %d  cannot be allocated  external fragmentation: %d\n",i+1,exfrag());
        }else
        {
            printf("process no: %d  allocated to block no: %d  space aquired: %d  internal fragmentation: %d\n",i+1,blk+1,proc[i],blocks[blk]-proc[i]);
            flag[blk]=1;
        }
    }
}

void firstfit()
{
    printf("\n* * *  First Fit  * * *\n");
    int* alloc=malloc(4*B);
    int i,j;
    for(i=0;i<B;i++)
    {
        flag[i]=0;
        alloc[i]=-1;
    }
    for(j=0;j<N;j++)
    {
        for(i=0;i<B;i++)
        {
            if(flag[i]==0&&blocks[i]>=proc[j])
            {
                printf("process no: %d  allocated to block no: %d  space aquired: %d  internal fragmentation: %d\n",j+1,i+1,proc[j],blocks[i]-proc[j]);
                flag[i]=1;
                i=B+1;
            }
        }
        if(i==B)
        {
            int ef=0;
            int t;
            for(t=0;t<B;t++)
            {
                if(flag[t]==0)
                    ef+=blocks[t];
            }
            printf("process no: %d  cannot be allocated  external fragmentation: %d\n",j+1,ef);
        }
    }
}





















