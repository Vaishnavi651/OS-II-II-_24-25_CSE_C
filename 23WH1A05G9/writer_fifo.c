#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd;
	char msg[100];
	mkfifo("myfifo",0666);
	while (1) {
        fd = open("myfifo", O_WRONLY);
        printf("Enter message: ");
        fgets(msg, sizeof(msg), stdin);
        
       
        write(fd, msg, strlen(msg) + 1);
        close(fd);

        if (strncmp(msg, "exit", 4) == 0) {
            break;
        }
    }
	return 0;
}
