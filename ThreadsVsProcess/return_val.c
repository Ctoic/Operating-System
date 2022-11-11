#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* roll_dice()
{
    int value = (rand()%6)+1;
    int* result = malloc(sizeof(int));

    *result = value;

    return (void**) result;
}

int main(int argc , void* argv[])
{
    int* res ;

    pthread_t thread;
    srand(time(NULL));

    if(pthread_create(&thread , NULL , &roll_dice , NULL)!=0)
    {
        return 1;
    }    
    if(pthread_join(thread, (void**
    )&res)!=0)
    { 
        return 2;
    }    

    printf("THe returned Value from Function %d : ", *res);


    return 0;
}