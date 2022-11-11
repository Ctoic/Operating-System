// TASK# 05
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void * thread_function1 ( void *args);
void * thread_function2 ( void *args);
pthread_t tid1 , tid2 ;
int main(){
pthread_create(&tid1 , NULL, thread_function1 , NULL) ;
pthread_create(&tid2 , NULL, thread_function2 , NULL) ;
sleep (1);
printf("Main thread:Canceling thread 1 ...\n"); pthread_cancel(tid1
);
printf("Main thread: exiting\n");
pthread_exit (NULL) ;
}
void * thread_function1(void *arg){
int i , oldstate , oldtype ; 
pthread_setcancelstate (PTHREAD_CANCEL_ENABLE,& oldstate ) ;
pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &oldtype);
// pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS,&oldtype );
// sleep (1);
printf ( "Thread 1:my old cancel state was %d and old cancel type was %d\n", oldstate, oldtype);
for(i = 0; i < 5; i++) {
printf("Thread 1:iam running (%d)\n",i);
if (i==1){
printf("Thread 1: iam waiting for thread 2 to finish\n");
pthread_join(tid2, NULL);}
}
// Following statement will never run !!!!!
printf("Thread 1:Thread 1 exited, nowme aswell\n");
pthread_exit (0);
}
void * thread_function2(void *arg){
int i;
sleep (2);
for(i = 0; i < 5; i++) {
printf("Thread 2:iam running (%d)\n",i);
printf ( "Thread 2: thread 1 received cancel signal but is waiting for me to finish\n" );
}
printf("Thread 2:iam exiting\n");
pthread_exit (0);
}