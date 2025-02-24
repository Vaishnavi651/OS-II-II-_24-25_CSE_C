#include <stdio.h>
#include <stdlib.h>  // Include for exit()

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork Failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        execlp("ls", "ls", NULL);
        perror("exec Failed");  // This will only be reached if execlp fails
        exit(1);                // Exit if exec fails

    }
    else {
        printf("Parent PID: %d\n", getpid());
        int status;
        wait(&status);
        printf("Child process finished with status %d\n", WEXITSTATUS(status));
    }
    return 0;
}
