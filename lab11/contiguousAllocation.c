#include<stdio.h>
#include<stdlib.h>

typedef struct file{
    char name[100];
    int start,size; 
}file;

int count;
file* files;
int mem,blk;
   
void main()
{

   printf("Enter the total memory size\n");
   scanf("%d",&mem);
   printf("Enter the block size\n");
   scanf("%d",&blk);
   int n=mem/blk;
   count=0;
   files=malloc(sizeof(file)*20);
   int i;
   do{
        printf("Enter 1 for file input AND 0 for exit\n");
        scanf("%d",&i);
        if(i==0)
            return;
        printf("Enter start address , file size , filename\n");
        scanf("%d %d %[^\n]",&files[count].start,&files[count].size,files[count].name);
        int j,st=files[count].start,blks=files[count].size/blk;
        if(files[count].size%blk!=0)
            blks+=1;
        int flag=0;
        for(j=0;j<count;j++)
        {
            flag=check(j,count);
        }
        if(flag==0)
        {
            printf("file: %s is allocated from %d to %d\n",files[count].name,files[count].start,end(count));
            count++;       
        }else{
            printf("This filer cannot be allocated because memory is already allocated\n");
        }
   }while(i!=0);
}

int check(int a,int b)
{
    int m=files[a].start,n=end(a);
    int x=files[b].start,y=end(b);
    if(x>m&&y>m)
    {
        if(x>n&&y>n)
        {
            return 0;
        }
    }else if(x<m&&y<m)
    {
        if(x<n&&y<n)
            return 0;
    }
    return 1;
}

int end(int a)
{
    int blks=files[a].size/blk;
    if(files[a].size%blk!=0)
        blks+=1;
    return files[a].start+blks-1;
}














