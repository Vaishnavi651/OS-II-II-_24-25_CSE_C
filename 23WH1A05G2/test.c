#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int  main(){
	pid_t pid=fork();
	if(pid<0){
		perror("fork creation fails");
		return 1;
	}
	else if(pid==0){
		printf("child process is created with (pid:%d)\n",getpid());
		execl("./5g2","./5g2",NULL); //fcfs program code 
		perror("error");
		return 1;


	}
	else{
		printf("parent process created with (pid:%d)\n",getpid());
		int status;
		wait(&status);
		if(WIFEXITED(status)){
				printf("child process ended with (pid:%d)\n",WEXITSTATUS(status));
		}
		else{
			printf("child process did not end normally\n");
		}
		printf("parent process ended\n");
	}
	return 0;
}






