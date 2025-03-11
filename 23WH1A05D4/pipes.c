#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    pipe(pipefd);
    pid = fork();

    if (pid == 0) {
        close(pipefd[1]);
        read(pipefd[0], read_msg, sizeof(read_msg));
        printf("Child process received: %s\n", read_msg);
        close(pipefd[0]);
    } else {
        close(pipefd[0]);
        write(pipefd[1], write_msg, sizeof(write_msg));
        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}

