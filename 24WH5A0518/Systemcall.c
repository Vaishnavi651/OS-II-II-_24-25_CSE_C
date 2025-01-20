#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 
    int status;

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        exit(EXIT_FAILURE);
    } else {
        pid_t waitResult = waitpid(pid, &status, 0);
        if (waitResult == -1) {
            perror("waitpid failed");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("Child Process (PID = %d) terminated with exit status: %d\n", pid, WEXITSTATUS(status));
        }
    }

    return 0;
}
