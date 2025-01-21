#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/wait.h>
#include<unistd.h>
int main(int argc,char **argv){

pid_t pid;

pid=fork();
if(pid<0){
	printf("Fork failed");
	exit(1);
}else if(pid==0){
	printf("Child process pid PID:%d is running ls\n",getpid());
	execlp("ls","ls",(char*)0);  /*"-af","/"*/
	perror("execlp failed");
	exit(1);
}else{
int status;
printf("Parent process pid:%d is waiting for child pid:%d\n",getpid(),pid);
wait(&status);

if(WIFEXITED(status)){
printf("Child process has exited with status:%d",WEXITSTATUS(status));
}
return 0;
}




}
