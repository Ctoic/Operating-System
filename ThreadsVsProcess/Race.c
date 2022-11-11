#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int mails  = 0 ;
pthread_mutex_t mutex;


void* routine()
{
    for(int i  = 0 ; i <1000000 ; i++)
        {
            // Wait unti the lock is 0
                pthread_mutex_lock(&mutex);
                mails++;
                pthread_mutex_unlock(&mutex);

        }
}

int main(int argc , void* argv[])
{
    pthread_t thread[4];
    int i ;
    for(i = 0 ;i<4;i++)
    {
        if(pthread_create(thread + i, NULL ,&routine,NULL) !=0)
        {
            return 1;
        }
        
    }
    for(i=0;i<4;i++)
    {
        printf("Thread %d has started \n",i);
        if(pthread_join(thread[i],NULL)!=0)
        {
            return 2;
        }
        printf("THread %d has finsih esecution \n",i);
    }
    pthread_mutex_init(&mutex , NULL);    

    pthread_mutex_destroy(&mutex);

    printf("Number of mails : %d \n", mails);
    return 0;
}