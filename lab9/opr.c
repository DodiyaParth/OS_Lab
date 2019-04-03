#include<stdio.h>
#include<stdlib.h>

int NF,NI;
int* seq;
int* frame;
int pageHit,pageFault;
int* check;

void opr();

void main()
{
    int i;
    pageHit=0;
    pageFault=0;
    
    printf("Enter Frame size\n");
    scanf("%d",&NF);
    frame=malloc(4*NF);
    check=malloc(4*NF);
    for(i=0;i<NF;i++)
        frame[i]=-1;
        
    printf("Enter Number of Sequence\n");
    scanf("%d",&NI);
    seq=malloc(4*NI);
    
    printf("Enter sequence of size %d\n",NI);
    for(i=0;i<NI;i++)
        scanf("%d",&seq[i]);
    
    opr();
}

void printFrame()
{
    int i;
    printf("| ");
    for(i=0;i<NF;i++)
    {
        if(frame[i]==-1)
            printf("_ ");
        else
            printf("%d ",frame[i]);
        printf("| ");
    }
}

int opInd(int cur)
{
    int i,j,count=NF;
    for(i=0;i<NF;i++)
        check[i]=0;
    for(i=cur+1;i<NI;i++)
    {
        for(j=0;j<NF;j++)
        {
            if(frame[j]==seq[i])
            {
                check[j]=1;
                count--;
            }
        }
        if(count==1)
        {
            for(j=0;j<NF;j++)
            {
                if(check[j]==0)
                    return j;
            }
        }
    }
    for(j=NF-1;j>=0;j--)
    {
        if(check[j]==0)
            return j;
    }
}

void opr()
{
    int i,j,t;
    for(i=0;i<NI;i++)
    {
        for(j=0;j<NF;j++)
        {
            if(frame[j]==seq[i])
            {
                //page hit
                printFrame();
                printf("Page Hit for %d\n",seq[i]);
                pageHit++;
                break;
            }
            else if(frame[j]==-1)
            {
                //initial page fault
                frame[j]=seq[i];
                printFrame();
                printf("Page Fault for %d\n",seq[i]);
                pageFault++;
                break;
            }
        }
        if(j==NF)
        {
            //page fault
            int ind=opInd(i);
            frame[ind]=seq[i];
            
            printFrame();
            printf("Page Fault for %d\n",seq[i]);
            pageFault++;
        }
    }
    printf("\nPageFault = %d\nPageHit = %d\n",pageFault,pageHit);
}

















