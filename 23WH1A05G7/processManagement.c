#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid1 == 0) {
        
        printf("Child 1 (PID: %d) is executing.\n", getpid());
        
        sleep(2);
        printf("Child 1 (PID: %d) is exiting.\n", getpid());
        exit(0);
    } else {
        
        pid2 = fork();
        if (pid2 < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid2 == 0) {
            
            printf("Child 2 (PID: %d) is executing.\n", getpid());
            
            sleep(3);
            printf("Child 2 (PID: %d) is exiting.\n", getpid());
            exit(0);
        } else {
            
            printf("Parent (PID: %d) waiting for children to finish.\n", getpid());
            wait(NULL);
            wait(NULL);
            printf("Parent (PID: %d) has finished waiting for children.\n", getpid());
        }
    }
    
    return 0;
}
