#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


void * function()
{
    print("Hello World");
}


int main(int argc , void* argv[])
{
    int pid = fork();
    if(pid == -1 )
    {
        wait(NULL);
    }

    return  0;
    


}