#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid, child_pid;
    int status;
    pid = fork();
    
    if (pid < 0) {
        // If fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        printf("Child process: Executing 'ls' command\n");
        execlp("/bin/ls", "ls", "-l", (char *)NULL);
        perror("Exec failed");
        exit(1);
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        printf("Parent process: Waiting for child process to terminate\n");
        child_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Parent process: Child (PID: %d) terminated with exit status %d\n", child_pid, WEXITSTATUS(status));
        } else {
            printf("Parent process: Child (PID: %d) did not terminate normally\n", child_pid);
        }
        printf("Parent process: Using waitpid to wait for specific child process\n");
        child_pid = waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Parent process: Child (PID: %d) terminated with exit status %d\n", child_pid, WEXITSTATUS(status));
        } else {
            printf("Parent process: Child (PID: %d) did not terminate normally\n", child_pid);
        }
    }
    return 0;
}
