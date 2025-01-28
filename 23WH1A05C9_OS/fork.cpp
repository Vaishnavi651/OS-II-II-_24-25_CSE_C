#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid=fork();
	if(pid==0){
		printf("child process\n");
		execlp("/bin/ls", "ls", NULL);
	}
	else if (pid > 0) {	
		wait(NULL);
		printf("Child process terminated\n");
	} else {
      printf("Fork failed\n");
    }

return 0;
}
