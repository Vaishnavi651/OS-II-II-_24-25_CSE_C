#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    int pipefd[2]; 
    pid_t pid;
    char write_msg[] = "Hello from parent process!";
    char read_msg[BUFFER_SIZE];

    
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    
    pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
    
    if (pid > 0) { 
        close(pipefd[0]); 
        write(pipefd[1], write_msg, strlen(write_msg) + 1);
        close(pipefd[1]); 
    } else { 
        close(pipefd[1]); 
        read(pipefd[0], read_msg, BUFFER_SIZE);
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]); 
    }
    
    return 0;
}

