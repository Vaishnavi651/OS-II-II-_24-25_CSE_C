#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t pid;
    char write_msg[100] = "Hello from the parent process!";
    char read_msg[100];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) { // Parent process
        close(fd[0]); // Close reading end of the pipe
        write(fd[1], write_msg, strlen(write_msg) + 1); // Write to the pipe
        close(fd[1]); // Close writing end of the pipe
        printf("Parent sent: %s\n", write_msg);
    } else { // Child process
        close(fd[1]); // Close writing end of the pipe
        read(fd[0], read_msg, sizeof(read_msg)); // Read from the pipe
        printf("Child received: %s\n", read_msg);
        close(fd[0]); // Close reading end of the pipe
    }

    return 0;
}
