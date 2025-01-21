#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid, wpid;
    int status;

    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Child process: PID = %d\n", getpid());
        printf("Child is executing 'ls' command using exec...\n");
        execlp("ls", "ls", "-l", (char *)NULL);
        perror("Exec failed");
        exit(1);
    } else {
        printf("Parent process: PID = %d\n", getpid());
        wpid = waitpid(pid, &status, 0);
        if (wpid == -1) {
            perror("waitpid failed");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }

        printf("Parent process ends.\n");
    }

    return 0;
}

