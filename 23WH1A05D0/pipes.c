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
    } else if (pid == 0) {  
        close(fd[1]);  
        ssize_t bytesRead = read(fd[0], buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';
        printf("Parent process sending Message : %s\n", buffer);	
        printf("Child process received Message : %s\n", buffer);
        close(fd[0]);  
    } else {  
        close(fd[0]);  
        char msg[] = "Hello from parent process!";
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);  
    }

    return 0;
}

