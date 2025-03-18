#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
        int fd[2];
        char buffer[100];

        if(pipe(fd) == -1){
                perror("pipe failed");
                return 1;
        }

        pid_t pid = fork();

        if(pid == -1){
                perror("fork failed");
                return 1;
        }
        else if(pid == 0){
                close(fd[1]);
                read(fd[0], buffer, sizeof(buffer));
                close(fd[0]);
                printf("Child process read from the pipe: %s\n", buffer);

        }
        else{
                close(fd[0]);
                char *msg = "Hello from child process";
                write(fd[1], msg, strlen(msg) + 1);
                close(fd[1]);
                printf("Parent process wrote to the pipe: %s\n", msg);

        }

        return 0;
}
