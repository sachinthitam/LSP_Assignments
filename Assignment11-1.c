#include<stdio.h>   //Standard I/O functions
#include<stdlib.h>    //Standard library functions
#include<unistd.h>    //POSIX operating system API (including fork() and execl())
#include<fcntl.h>     //File control options
#include<pthread.h>    // primary functionalities provided by the pthread.h header like pthread_create,pthread_exit,pthread_join

void * ThreadProc1(void *ptr)
{
  printf("Inside thread 1\n");
  pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
  printf("Inside thread 2\n");
  pthread_exit(NULL);
}
void * ThreadProc3(void *ptr)
{
  printf("Inside thread 3\n");
  pthread_exit(NULL);
}
void * ThreadProc4(void *ptr)
{
 printf("Inside thread 4\n");
  pthread_exit(NULL);
}

int main()
{
    pthread_t TID1, TID2,TID3,TID4;
    int ret1 = 0, ret2 = 0, ret3 = 0, ret4 =0;

    ret1 = pthread_create(&TID1,        
                          NULL,       
                          ThreadProc1, 
                          NULL);      

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread1 is created with ID : %d\n",TID1);

    ret2 = pthread_create(&TID2,        
                          NULL,       
                          ThreadProc2, 
                          NULL);      

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread2 is created with ID : %d\n",TID2);

    ret3 = pthread_create(&TID3,        
                          NULL,       
                          ThreadProc3, 
                          NULL);      

    if(ret3 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread3 is created with ID : %d\n",TID3);


 ret4 = pthread_create(&TID4,        
                        NULL,       
                        ThreadProc4, 
                        NULL);      

    if(ret4 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread4 is created with ID : %d\n",TID4);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);


    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}