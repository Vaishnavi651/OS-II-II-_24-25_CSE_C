#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define BUFFER_SIZE 100

int main() {
	int fd_read, fd_write;
	char read_msg[BUFFER_SIZE],write_msg[BUFFER_SIZE];

	mkfifo(FIFO1, 0666);
	mkfifo(FIFO2, 0666);

	fd_read = open(FIFO1, O_RDONLY);
	if(fd_read == -1) {
		perror("open read failed");
		exit(1);
	}

	fd_write = open(FIFO2, O_WRONLY);
	if(fd_write == -1) {
		perror("open write failed");
		exit(1);
	}

	while(1) {
		read(fd_read, read_msg, BUFFER_SIZE);
		printf("Received from Writer : %s", read_msg);

		if(strncmp(read_msg, "exit", 4) == 0) {
			break;
		}

		printf("Enter reply: ");
		fgets(write_msg,BUFFER_SIZE,stdin);
		write(fd_write, write_msg, strlen(write_msg) + 1);

		if(strncmp(write_msg, "exit",4) == 0) {
			break;
		}
	}

	close(fd_read);
	close(fd_write);

	return 0;
}


