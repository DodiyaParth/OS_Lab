#include<stdio.h>
#include<stdlib.h>

int alloc[100][100],max[100][100],need[100][100];
int n;
int avail[100];

void main()
{
    int res,i,k;
    n=0;
    printf("Enter the number of resources\n");
    scanf("%d",&res);
    printf("Enter available %d resources\n",res);
    for(i=0;i<res;i++)
        scanf("%d",&avail[i]);
    
    int temp;
    do{
        printf("\nEnter choice\n1. New Process  0. Break\n");
        scanf("%d",&temp);
        if(temp==1)
        {
            printf("Enter allocated resource to process %d\n",n+1);
            for(i=0;i<res;i++)
                scanf("%d",&alloc[n][i]);
            printf("Enter max resources process %d wants\n",n+1);
            for(i=0;i<res;i++)
                scanf("%d",&max[n][i]);
            int flag=0;
            for(i=0;i<res;i++)
            {
                if(max[n][i]-alloc[n][i]>avail[i])
                    flag=1;               
            }
            if(flag==0)
            {
                for(i=0;i<res;i++)
                    avail[i]+=alloc[n][i];
                printf("Safe Sequence\n");
            }else
            {
                printf("Deadlock\n");
            }
            printf("\nAvailable resources: ");
            for(i=0;i<res;i++)
                printf(" %d",avail[i]);
            printf("\n");
            n++;
        }
    }while(temp!=0);
    
}
