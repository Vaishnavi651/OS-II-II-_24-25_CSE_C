#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>  

#define BUFFER_SIZE 100

int main() {
    int pipefd[2];
    pid_t pid;
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];

    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        
        close(pipefd[0]); 

        while (1) {
           
            printf("Enter a message to send (type 'exit' to quit): ");
            fgets(write_msg, sizeof(write_msg), stdin);
            write_msg[strcspn(write_msg, "\n")] = 0; 

           
            if (strcmp(write_msg, "exit") == 0) {
                break;
            }

           
            write(pipefd[1], write_msg, strlen(write_msg) + 1);
        }

        close(pipefd[1]);
        wait(NULL);  
    } else {
        
        close(pipefd[1]);  

        while (1) {
           
            ssize_t n = read(pipefd[0], read_msg, sizeof(read_msg));
            if (n == 0) {
                break; 
            }
            printf("Receiver received: %s\n", read_msg);
        }

        close(pipefd[0]); 
        exit(0);
    }

    return 0;
}

