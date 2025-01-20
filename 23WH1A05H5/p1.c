#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	pid_t pid,p2;
	pid=fork();
	if(pid<0){
		perror("Fork Failed");
		exit(-1);
	}
	else if(pid==0){
		printf("child process of Pid = %d\n",getpid());
		execlp("ls","ls",NULL);
		
		execlp("wc","wc","fcfs.c",NULL);
		perror("In exec(): ");
	}
	else{	
		printf("parent process of Pid = %d\n",getpid());
		int s;
		wait(&s);
		wait(NULL);
		exit(0);
	}
}
		
