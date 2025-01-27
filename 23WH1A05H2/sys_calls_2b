#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
        int fd;
        char buffer[100];
        fd = open("test.txt",O_WRONLY|O_CREAT,0644);
        if(fd==-1){
                printf("Error! failed in creating a file");
                return 1;
        }
        write(fd,"Hello, I am Varshini, nice to meet you!", 39);
        close(fd);
        fd = open("test.txt",O_RDONLY);
        if(fd==-1){
                perror("Error has occured");
        }
        read(fd,buffer,sizeof(buffer));
        printf("Reading from file...%s",buffer);
        close(fd);

}

