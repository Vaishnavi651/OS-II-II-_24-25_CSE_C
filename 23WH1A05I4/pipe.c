#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[128];

    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid = fork();
    
    if (pid <0) {
        perror("fork failed");
        return 1;
    }
    
    else if (pid == 0) {  
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(pipefd[0]);
    } else {  
        close(pipefd[0]);

  
        const char* msg = "Hello from parent process!";
        write(pipefd[1], msg, strlen(msg) + 1);
        
      
        close(pipefd[1]);
    }

    return 0;
}

