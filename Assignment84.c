#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid1, pid2;
    int status1, status2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("Fork failed");
        
    } else if (pid1 == 0) {
        // This is Process 2
        pid2 = getpid();
        printf("Process 2 (PID = %d) is created by Process 1 (Parent).\n", pid2);
        // Do some work in Process 2 here
        sleep(2); 
        printf("Process 2 is exiting.\n");
    
    } else {
        // This is the parent process (Process 1)
        printf("Parent process (PID = %d) is creating Process 3.\n", getpid());

        pid2 = fork();

        if (pid2 < 0) {
            perror("Fork failed");
           
        } else if (pid2 == 0) {
            // This is Process 3
            pid2 = getpid();
            printf("Process 3 (PID = %d) is created by Process 1 (Parent).\n", pid2);
            
            sleep(3); 
            printf("Process 3 is exiting.\n");
          
        } else {
            // This is the parent process (Process 1)
            wait(&status1);
            printf("Parent process (PID = %d) is waiting for Process 2 to terminate.\n", getpid());

            wait(&status2);
            printf("Parent process (PID = %d) is waiting for Process 3 to terminate.\n", getpid());

            printf("Parent process is exiting.\n");
         
        }
    }

    return 0;
}
