#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fnctl.h>
int main(){
        int fd;
        char buf[100];
         fd=open("do.txt",O_WRONLY,6605);
         if(fd==-1){
                 perror("Error occured");
                 return 1;
         }
         write(fd,"Hello, World\n",14);
        close(fd);
        fd=open("do.txt",O_RDONLY);
        if(fd==-1){
                perror("Error occured: ");
        }
        read(fd,buf,sizeof(buf));
        printf("REad from file : %s",buf);
        close(fd);
}
