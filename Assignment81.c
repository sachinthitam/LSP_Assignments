//write a program in which parent process waits till its child process get terminate

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = fork();
	
    if (Ret < 0) {
        printf("Fork failed\n");
	}
    else if(Ret == 0)
    {
        printf("Child process is running\n");
    }
	//child process terminated
    else
    {
        printf("Parent process is running\n");
    }
	//parent process terminated
    
    return 0;
}