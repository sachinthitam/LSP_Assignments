//program which create three level process hierarchy where process 1 create process 2 and it internally create process 3 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int PID1;
	int PID2;
	int PID3;
	
    int status;

    PID1 = getpid();
    printf("Process 1 (PID = %d) is creating Process 2.\n", PID1);

    PID2 = fork();

    if (PID2 < 0) {
        printf("Fork failed\n");
   
    } else if (PID2 == 0) {
        // This is Process 2
        PID2 = getpid();
        printf("Process 2 (PID = %d) is created by Process 1 (PID = %d).\n", PID2, PID1);
        printf("Process 2 is creating Process 3.\n");

        PID3 = fork();

        if (PID3 < 0) {
            printf("Fork failed");
       
        } else if (PID3 == 0) {
            // This is Process 3
            PID3 = getpid();
            printf("Process 3 (PID = %d) is created by Process 2 (PID = %d).\n", PID3, PID2);
           
   
        } else {
            // This is Process 2, continue its execution
            wait(&status);
            printf("Process 2 (PID = %d) is waiting for Process 3 (PID = %d) to terminate.\n", PID2, PID3);
            printf("Process 2 is exiting.\n");
        
        }
    }
	else {
        // This is Process 1, continue its execution
        wait(&status);
        printf("Process 1 (PID = %d) is waiting for Process 2 (PID = %d) to terminate.\n", PID1, PID2);
        printf("Process 1 is exiting.\n");
       
    }

    return 0;
}
