#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	pid_t pid = fork();
	int status;
	if(pid < 0){
		perror("fork failled to execute");
		return 1;
	}
	else if(pid == 0){
		printf("\nchild process (PID:%d) executing 'fcfs' CPU scheduling\n",getpid());
		execlp("./fcfs","./fcfs",NULL);
		perror("execution failled");
		exit(1);
	}
	else{
		printf("\nparent process (PID:%d) waiting for child to finish\n",getpid());
		pid_t child_pid = wait(&status);
		if(child_pid < 0)
		perror("wait failled....");
		printf("\nchild process (PID:%d) finished with status : %d\n",child_pid,WEXITSTATUS(status));
		return 0;
	}
	return 0;
}
		
		
