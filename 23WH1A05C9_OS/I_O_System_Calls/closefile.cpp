#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd=open("example.txt",O_RDONLY);
	
	if(fd<1){
		perror("c1");
		exit(1);
	}
	
	printf("opened the fd=%d\n",fd);
	
	//using the system call
	
	if(close(fd)<0){
		perror("error");
		exit(1);
	}
	
	printf("closed the fd.\n");
	
	
	
}
