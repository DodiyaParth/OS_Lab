#include<stdio.h>
#include<stdlib.h>

int NF,NI;
int* seq;
int* frame;
int pageHit,pageFault;
int* fc;

void lru();

void main()
{
    int i;
    pageHit=0;
    pageFault=0;
    
    printf("Enter Frame size\n");
    scanf("%d",&NF);
    frame=malloc(4*NF);
    fc=malloc(4*NF);
    for(i=0;i<NF;i++){
        frame[i]=-1;
        fc[i]=0;   
    }
        
    
    printf("Enter Number of Sequence\n");
    scanf("%d",&NI);
    seq=malloc(4*NI);
    
    printf("Enter sequence of size %d\n",NI);
    for(i=0;i<NI;i++)
        scanf("%d",&seq[i]);
    
    lru();
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

int lr()
{
    int i,max=0,ind=-1;
    for(i=0;i<NF;i++)
    {
        if(fc[i]>max)
        {
            max=fc[i];
            ind=i;
        }
    }
    return ind;
}

void lru()
{
    int i,j,t;
    for(i=0;i<NI;i++)
    {
        for(j=0;j<NF;j++)
        {
            if(frame[j]==seq[i])
            {
                //hit
                printFrame();
                printf("Page Hit for %d\n",seq[i]);
                pageHit++;
                for(t=0;t<NF;t++)
                {
                    if(frame[t]==seq[i])
                        fc[t]=0;
                    else
                        fc[t]++;
                }
                break;
            }
            else if(frame[j]==-1)
            {
                //starting fault
                frame[j]=seq[i];
                printFrame();
                printf("Page Fault for %d\n",seq[i]);
                pageFault++;
                for(t=0;t<NF;t++)
                {
                    if(frame[t]!=seq[i])
                        fc[t]++;
                    if(frame[t]==seq[i])
                        fc[t]=0;
                }
                break;
            }
        }
        if(j==NF)
        {
            //Fault    
            int ind=lr();
            frame[ind]=seq[i];
            printFrame();
            printf("Page Fault for %d\n",seq[i]);
            pageFault++;
            for(t=0;t<NF;t++)
            {
                if(frame[t]==seq[i])
                    fc[t]=0;
                else
                    fc[t]++;
            }
        }
    }
    printf("\nPageFault = %d\nPageHit = %d\n",pageFault,pageHit);
}




















