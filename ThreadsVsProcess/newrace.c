#include<stdint.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
int incre = 0 ;
pthread_mutex_t mutex;


void* increment()
{

    incre++;

}


int main(int argc , void* argv[])
{
    // create array of threads 
    pthread_t thread[8];
    for(int i = 0 ; i<8 ; i++)
    {
        printf("Thread %d has been created \n",i);

        if(pthread_create(thread+1 , NULL , &increment, NULL)!=0)
        {
            return 1 ;
        }
    }
    for(int i = 0 ; i <8 ; i++)
    {
        printf("Thread %d has been Ended Execution \n",i);
        if(pthread_create(&thread[i], NULL , &increment, NULL)!=0)
        {
            return 0;
        }
    }

    pthread_mutex_init(&mutex , NULL);
    pthread_mutex_destroy(&mutex);

    printf("Number of Timess it Incremented: %d",incre);


    return 0;

}