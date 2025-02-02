#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BS 100

int main(){
    int fd=open("f1.txt", O_RDONLY);
    if(fd<0){
        perror("open");
        exit(1);
    }
    pid_t pid=fork();
    if(pid<0){
        perror("fork");
        close(fd);
        exit(1);
    }
    if(pid==0){ 
        char buf[BS];
        ssize_t n = read(fd, buf, BS - 1);
        if(n<0){
            perror("read");
            close(fd);
            exit(1);
        }
        buf[n] = '\0';
        printf("Child: Read content:\n%s\n", buf);
    } else { 
        wait(NULL);
        printf("Parent: Child finished reading.\n");
    }

    close(fd);
    return 0;
}

