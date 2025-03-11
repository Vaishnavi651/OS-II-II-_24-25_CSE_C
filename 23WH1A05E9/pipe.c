#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int fd[2]; 
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {  // Child Process
        close(fd[1]);  // Close write end of the pipe
        ssize_t bytesRead = read(fd[0], buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';  // Null-terminate the string
        printf("Child received: %s\n", buffer);
        close(fd[0]);  // Close read end of the pipe
    } else {  // Parent Process
        close(fd[0]);  // Close read end of the pipe
        char msg[] = "Hello from parent!";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);  // Close write end of the pipe
    }

    return 0;
}

