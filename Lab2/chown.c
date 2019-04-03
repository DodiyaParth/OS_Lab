#include <unistd.h>
#include<stdio.h>

void main()
{
    int a=chown("hello.txt",1000,108);
    printf("Change owner status=%s\n",a==0?"Yes\n":"No\n");
}
