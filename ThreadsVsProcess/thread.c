#include<stdio.h>
#include<stdlib.h>
#include<pthread>

void* function()
{
    printf("THread was created ");
}

int main()
{
    pthread_t thread1 ;
    pthread_create(&thread1 , NULL , &function , NULL);
    pthread_join(thread1 , NULL);

    return 0;



}