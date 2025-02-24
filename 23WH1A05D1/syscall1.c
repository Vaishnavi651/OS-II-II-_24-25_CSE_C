#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork(); // Create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) { // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        char *args[] = {"/bin/ls", "-l", NULL};
        execvp(args[0], args); // Execute new program
        perror("exec failed"); // If exec fails
        exit(1);
    }
    else { // Parent process
        printf("Parent Process: Waiting for child (PID = %d)\n", pid);
        waitpid(pid, &status, 0); // Wait for child to terminate
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
        else {
            printf("Child process did not terminate normally\n");
        }
    }
    return 0;
}

