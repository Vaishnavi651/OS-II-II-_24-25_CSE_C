#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char message[] = "Hello from the pipe!";
    char buffer[100];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    if (fork() == 0) {
        // Child process
        close(pipefd[0]); // Close reading end
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]); // Close writing end
    } else {
        // Parent process
        close(pipefd[1]); // Close writing end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Received message: %s\n", buffer);
        close(pipefd[0]); // Close reading end
    }

    return 0;
}

