#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t pid;
	pid = fork();
	int status;
	
	if(pid<0){
		perror("\nFORK FAILED.");
		return 1;
	}
	else if(pid==0){
		printf("\nI am child process(pid: %d)",pid);
		execlp("sudo","sudo","apt","update",NULL);
		perror("\nExecution FAILED.");
		exit(1);
	}
	else{
		printf("\nI am parent process(pid: %d) and waiting for child process(pid: %d)",pid,getpid());
		pid_t childpid = wait(&status);
		if(childpid<0) printf("\nThe child process(pid=%d) terminated abnormally",childpid);
		printf("\nThe child process(pid=%d) is exited with status %d",childpid,WEXITSTATUS(status));
		return 0;
	}
	return 0;
}



