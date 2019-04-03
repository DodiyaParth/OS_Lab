#include<stdio.h>
#include<stdlib.h>

int n,m;
int* available,work;
int** max,allocation,need;
int* sequence;
int* isFinished;
void isSafe()
{
    int i,j,count=0;
    for(i=0;i<m;i++)
        work[i]=available[i];
    for(i=0;i<n;i++)
        isFinished[i]=0;
    while(count<n)
        {
                int canAllot=0;
                for(i=0;i<n;i++)
                {
                   if(isFinished[i]==0)
                   {

                        for(j=0;j<m;j++)    
                        {
                            if(work[j]<need[i][j])
                            {
                                break;
                            }
                        }
                        if(j==m)
                        {
                            for(j=0;j<m;j++)
                            {
                                work[j]+=allocation[i][j];
                            }

                            sequence[count++]=i;
                            isFinished[i]=1;
                            canAllot=1;
                        }
                   }
                }
                if(canAllot==1)
                {
                    printf("System Is  not safe\n");
                    return ;
                }
        }
        printf("System is in safe state\n");

        printf("Safe sequence :");
        for(i=0;i<n;i++)
            printf("%d ",sequence[i]);
        printf("\n");
}

void main()
{
    printf("Enter number of processes and number of resources\n");
    scanf("%d %d",&n,&m);
    available=malloc(4*m);
    work=malloc(4*m);
    isFinished=malloc(4*n);
    sequence=malloc(4*n);
    int i,j;
    max=malloc(sizeof(int*)*n);
    allocation=malloc(sizeof(int*)*n);
    need=malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
    {
        max[i]=malloc(4*m);
        allocation[i]=malloc(4*m);
        need[i]=malloc(4*m);
    }
    printf("enter available matrix\n");
    for(i=0;i<n;i++)
        scanf("%d",&available[i]); 
    printf("Enter max matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);
    printf("Enter allocation matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&allocation[i][j]);
    printf("Enter need matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&need[i][j]);   
    for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                need[i][j]=max[i][j]-allot[i][j];
    isSafe();   
         
}

















