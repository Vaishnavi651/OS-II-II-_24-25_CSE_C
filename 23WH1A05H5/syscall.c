#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid=fork();
    if(pid<0){
        perror("Fork Failed");
        exit(-1);
    }else if(pid==0){
        printf("Child process created with PID = %d", getpid());
        execlp("ls", "ls", NULL);
        perror("Error executing 'ls' command");
        exit(1);
    }else{ 
        printf("Parent process waiting. Parent PID = %d\n", getpid());
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child process finished. Exit status = %d\n", WEXITSTATUS(status));
        }else{
            printf("Child process terminated abnormally.\n");
        }
    }
    printf("Parent process exiting.\n");
    return 0;
}
