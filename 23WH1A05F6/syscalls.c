#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	pid_t p=fork();
	if(p<0){
		printf("error occured");
	}
	else if(p==0){
		printf("\nchild process %d",getpid());
		execlp("./fc","./fc",NULL);
		/*execlp("ls","ls","-l",NULL);*/

	}
	else{
		printf("parent process pid %d\t",getpid());
		int status;
        wait(&status);
        printf("Parent Process: Child has finished with status %d\n", status);
        exit(0);
	}
}
