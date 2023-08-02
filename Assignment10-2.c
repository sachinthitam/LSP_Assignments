#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>


void * ThreadProc1(void *ptr)
{
  int i = 0;

  for(i = 1; i <= 500; i++)
  {
    printf("Thread1 with counter : %d\n",i);
  }
  pthread_exit(NULL);
}
void * ThreadProc2(void *ptr)
{
  int i = 0;

  for(i = 1; i <= 500; i--)
  {
    printf("Thread2 with counter : %d\n",i);
  }
  pthread_exit(NULL);
}

int main()
{
    pthread_t TID1,TID2;
    int ret1 = 0, ret2 = 0;

    ret1 = pthread_create(&TID1,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc1, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret1 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID1);



    ret2 = pthread_create(&TID2,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc2, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    
    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}