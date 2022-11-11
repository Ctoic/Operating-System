#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void * thread_function ( void * arg ) ;
char message[] = "Iam thread 1";
int main(){
pthread_t tid ;
pthread_attr_t thread_attr ;
pthread_attr_init(&thread_attr );
//comment following line in 2nd run
pthread_attr_setdetachstate(&thread_attr ,PTHREAD_CREATE_DETACHED);
//uncomment following line in 2nd run
//pthread_attr_setdetachstate(&thread_attr ,PTHREAD_CREATE_JOINABLE);
pthread_create(&tid,&thread_attr ,thread_function ,(void*)message);
pthread_attr_destroy(&thread_attr );
int joinret ;
joinret=pthread_join(tid ,NULL);
if(joinret==0) //when join successfull
printf("join was successfull:The main thread was waiting for thread 1\n");
else
printf("Join failed:The main thread is not waiting for thread 1\n");
printf("The main thread finished , bye!\n");
pthread_exit (NULL) ;
}
void * thread_function(void *arg){
printf("thread_function is running. Argument was\" %s\"\n", (char*)arg);
sleep (4);
printf("thread awaked from sleep, and exiting now\n");
pthread_exit (NULL) ;
}