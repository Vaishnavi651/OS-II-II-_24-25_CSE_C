#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
    pid_t pid = fork();
    if(pid < 0){
        perror("fork failed");
        return 1;
    }else if(pid == 0){
        printf("%d", getpid());
        execlp("ls", "ls", NULL);
        perror("execution failed");
        exit(1);
    }else{
        printf("%d", getpid());
        int status;
        wait(&status);
        printf("child exited with status %d\n", WEXITSTATUS(status));
    }
    return 0;
}
