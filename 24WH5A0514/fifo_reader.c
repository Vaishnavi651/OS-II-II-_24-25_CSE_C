#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "my_fifo"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }
    read(fd, buffer, BUFFER_SIZE);
    printf("Reader: Received message - %s\n", buffer);
    close(fd);
    return 0;
}

