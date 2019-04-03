#include<unistd.h>
#include<stdio.h>
#include <sys/stat.h>

void main()
{
    int a=access("hello.txt",F_OK);
    if(a==0)
    {
        printf("File is exist\n");        
    }
    else
    {
        printf("file is not exist\n");
        return;
    }
    
         a=access("hello.txt",R_OK);
    printf("Read permission=%s",a==0?"yes\n":"no\n");
    
    a=access("hello.txt",W_OK);
    printf("Write permission=%s",a==0?"yes\n":"no\n");
    

    
     a=access("hello.txt",X_OK);
    printf("Excecute permission=%s",a==0?"yes\n":"no\n");
    
    //////
    printf("After changing the access using chmod\n");
    chmod("hello.txt",0477);
    ////////
    
    
     a=access("hello.txt",R_OK);
    printf("Read permission=%s",a==0?"yes\n":"no\n");
    
     a=access("hello.txt",W_OK);
    printf("Write permission=%s",a==0?"yes\n":"no\n");
    
     a=access("hello.txt",X_OK);
    printf("Excecute permission=%s",a==0?"yes\n":"no\n");
    
    chmod("hello.txt",0777);
    
}
