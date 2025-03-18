#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_SIZE 100

int main(){

int pipe_fd[2];
pid_t pid;
char input[MAX_SIZE];
char buffer[MAX_SIZE];

//to create pipe we use pipe() system call

if(pipe(pipe_fd)==-1){
	printf("Pipe creation failed\n");
	exit(1);
}

pid=fork();

if(pid<0){
	perror("Fork failed");
}
if(pid>0){
//parent process will write
close(pipe_fd[0]); //closing the read end
	printf("Enter a message to send to the child process:");
	fgets(input, MAX_SIZE,stdin);
	  write(pipe_fd[1], input, sizeof(input));
	  close(pipe_fd[1]); //closing the write after writing
}
else{ //child process
      close(pipe_fd[1]);//closing write
      read(pipe_fd[0], buffer, sizeof(buffer)); //reading the pipe
      printf("Child received the message:%s",buffer);
      close(pipe_fd[0]);	     
	
}
return 0;
}
