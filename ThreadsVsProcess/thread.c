#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* function()
{
    printf("THread was created ");
    printf("Again Thread came after three seconds");
}

int main()
{
    pthread_t thread1 ;
    pthread_t thread2;

    pthread_create(&thread1 , NULL , &function , NULL);
    pthread_create(&thread2 , NULL , &function , NULL);
    pthread_join(thread1 , NULL);
    pthread_join(thread2 , NULL);

    return 0;


}