#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid < 0){
		perror("fork failed");
		exit(1);
	}
	if(pid == 0){
		char *args[] = {"./c_program",NULL};
		execvp(args[0],args);
		perror("exec failed");
		exit(1);
	}else{
		printf("parent process : PID = %d , child PID = %d\n",getpid(),pid);
		int status;
		wait(&status);
		printf("parent process : child has finished with status %d\n",status);
		exit(0);
	}
	return 0;
}
