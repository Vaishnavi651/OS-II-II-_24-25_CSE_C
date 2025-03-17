#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "my_fifo"

int main() {
    int fd;
    char message[] = "Hello from the writer process!";
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }
    write(fd, message, sizeof(message));
    printf("Writer: Message sent.\n");
    close(fd);
    return 0;
}

