#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
int main(){
        int fd;
        char buffer[39];
        fd=open("Systemcall.txt",O_RDONLY,0644);
        if(fd<0){
                perror("Error occurred in opening the file");
                return 1;
        }
        read(fd,buffer,38);
        buffer[38]='\0';
	printf("File contents: %s",buffer);
        close(fd);
        return 0;
}

