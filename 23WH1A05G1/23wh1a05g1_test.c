#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t pid=fork();
	if(pid<0){
		perror("fork is not created");
		return 1;
	}
	else if(pid==0){
		printf("child process is not created with (pid:%d)\n",getpid());
		execl("./3","./3",NULL);
		perror("error");
	}
	else{
		printf("parent process is created with (pid:%d)\n",getpid());
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






