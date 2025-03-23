#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));
    printf("Reader: Received message: %s\n", buffer);

    close(fd);
    return 0;
}
