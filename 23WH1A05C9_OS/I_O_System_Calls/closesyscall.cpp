#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
	int fd=open("example.txt",O_RDONLY);
	close(fd);
	
	int fd2=open("foo.txt",O_RDONLY);
	printf("fd2=%d\n",fd2);
	
	exit(0);
}
