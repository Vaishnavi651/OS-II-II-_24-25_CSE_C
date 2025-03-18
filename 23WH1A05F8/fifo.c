#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO_NAME"/tmp/my_fifo"
int main(){
	if(mkfifo(FIFO_NAME,0666)== -1){
		perror;
		("mkfifo failed");
		exit(1);
	}
	pid_t pid = fork();
	if(pid<0){
		perror("fork failed");
		exit(1);
	}
	if(pid>0){
		int fd= open(FIFO_NAME,O_WRONLY);
		if(fd==-1){
			perror("parent opended faied");
			exit(1);
		}

		const char *msg="Hello from parent!";
		write(fd,msg,strlen(msg)+1);
		printf("parent:sent message:%s\n",msg);

		close(fd);
		wait(NULL);
	}
	else{
		int fd=open(FIFO_NAME,O_RDONLY);
		if(fd==-1){
			perror("child open failed)");
			exit(1);
		}
		char buffer[100];
		read(fd,buffer,sizeof(buffer));
		printf("child: received message:%s\n", buffer);
		close(fd);
	}
	unlink(FIFO_NAME);\
		return 0;

}


