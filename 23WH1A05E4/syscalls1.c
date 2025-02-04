#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
int main(){
	int fd;
	char buffer[100];
	fd = creat("Systemcalls.txt",0666);
	close(fd);
	return 0;
}
