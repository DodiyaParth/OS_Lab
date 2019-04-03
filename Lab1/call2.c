#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void main()
{   //open
    int fd=open("Hello.txt",O_RDWR,0777);
    printf("fd=%d\n",fd);
    if(fd==-1)
    {
        printf("Error in opening the file");
        return;
    }
    
    //read
    char* c=malloc(100);
    int sizeOfFile=read(fd,c,54);
    
    printf("\nAfter read 1\n");
     c[sizeOfFile]='\n';
    printf("size of file=%d\nstring:\n%s\n",sizeOfFile,c);
    sizeOfFile=read(fd,c,55);    
    
    
    printf("\nafter read 2\n");
    c[sizeOfFile]='\n';
    printf("size of file=%d\nstring:\n%s\n",sizeOfFile,c);
    //write
     lseek(fd,0,SEEK_END);
    char str[]="This string is created to append\n";
   
    int wr=write(fd,str,sizeof(str));
    printf("wr=%d\n",wr);
    
    //lseek
    lseek(fd,0,SEEK_SET);
   
    sizeOfFile=read(fd,c,100);    
    printf("\nafter write/ read 3\n");
    c[sizeOfFile]='\n';
    printf("size of file=%d\nstring:\n%s\n",sizeOfFile,c);
    
    //close
    int b=close(fd);
    if(b==-1)
        printf("Error in closing the file");
        
    int nfd=dup(fd);
    printf("New fd=%d\n",nfd);
    
    link("Hello.txt","test.txt");
    write(fd,"This is for test purpose",30);
    //unlink("");
}
