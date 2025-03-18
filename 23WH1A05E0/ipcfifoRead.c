#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[100];

    // Open the FIFO for reading
    fd = open("/tmp/myfifo", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Received from FIFO: %s\n", buffer);
    close(fd);

    return 0;
}

