#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc(void *ptr){
    
    pthread_t TID = pthread_self();

    printf("Thread ID: %ld\n", (long)TID);

    pthread_exit(NULL);
}

int main() {
    pthread_t TID;
    int ret= 0;

    ret = pthread_create(&TID,
	                 NULL,
			 ThreadProc,
			 NULL);
    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    pthread_join(TID, NULL);

    printf("End of main thread\n");
    
    pthread_exit(NULL);

    return 0;
}
