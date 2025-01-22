#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();  // Create a child process

    if (pid < 0) {
        perror("Fork Failed");  // If fork fails, terminate
        exit(-1);
    } else if (pid == 0) { 
        // Child process
        printf("Child process created with PID = %d, Parent PID = %d\n", getpid(), getppid());
        
        // Execute "ls -l" to list files in a detailed format
        execlp("ls", "ls",NULL);
        perror("Error executing 'ls' command");  // Executed if execlp fails
        exit(1);
    } else { 
        // Parent process
        printf("Parent process waiting. Parent PID = %d\n", getpid());
        int status;

        // Wait for the child process to complete
        wait(&status);

        // Check and print child's exit status
        if (WIFEXITED(status)) {
            printf("Child process finished. Exit status = %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally.\n");
        }
    }

    printf("Parent process exiting.\n");
    return 0;
}
