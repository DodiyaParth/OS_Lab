#include<stdio.h>
#include<stdlib.h>
int main()
{
printf("No of blocks is 50\n");
int f[50], p,i, st, len, j, c, k, a;
for(i=0;i<50;i++)
f[i]=0;
printf("Enter how many blocks already allocated: ");
scanf("%d",&p);
printf("Enter blocks already allocated: ");
for(i=0;i<p;i++)
{
 scanf("%d",&a);
 f[a]=1;
}
x: printf("Enter index starting block and length: ");
scanf("%d%d", &st,&len);
k=len;


if(f[st]==0)
{
 f[st] = 1;
 int temp1, temp2;
 temp2 = st;

for(j=1; j<=len; j++)
 {	temp1 = temp2;
	while(1)
	{
		temp2 = rand() % 50;
		if(f[temp2] == 0)
		break;
	}

 f[temp2]=1;
 printf("%2d-->%-2d\n",temp1, temp2);
 
 }
}
else
printf("%d starting block is already allocated \n",st);
printf("Do you want to enter more file\n1. YES 2.NO\n");
scanf("%d", &c);
if(c==1)
 goto x;
else
 exit(0);
}
