#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    pid_t pid;

    pid = fork();  // Create a new process
    if (pid < 0) {  // Error handling for fork()
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) {  // Child process
        printf("Child process pid: %d is running 'ls'\n", getpid());

        // Use system() to run the 'ls' command (this doesn't require execlp)
        int result = system("ls");

        if (result == -1) {
            perror("system() failed");
            exit(1);
        }

        exit(0);
    } else {  // Parent process
        int status;
        printf("Parent process pid: %d is waiting for child pid: %d\n", getpid(), pid);

        // Wait for the child process to exit
        wait(&status);

        // Check if the child process terminated normally
        if (WIFEXITED(status)) {
            printf("Child process has exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not terminate normally\n");
        }
    }

    return 0;
}


