/*Write a program to implement Process management system calls viz., fork, exit, wait,
waitpid, exec.*/

/*Replaces the current process's image with the ls program.
/bin/ls: The full path to the ls executable.
"ls": The name of the program.
"-l": An argument to ls for long listing format.*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h> 

int main(){
    pid_t pid;
    int status;
    pid=fork();

    if(pid<0){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("Child process(PID:%d).\n",getpid());
        execlp("/bin/ls","ls","-l",NULL);
        perror("Execution Failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Parent Process(PID:%d).\n",getpid());
        pid_t wait_pid= waitpid(pid,&status,0);
      //when waitpid is used wait can be ignored. wait is for simpler actions
        
        if(wait_pid>=0){
            printf("Child process (PID:%d) executed succuessfully",wait_pid);
        }
        else{
            perror("Wait Failed");
        }
    }
}
