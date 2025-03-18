#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    char message[] = "Hello from FIFO!";

    // Create a FIFO
    mkfifo("/tmp/myfifo", 0666);

    // Open the FIFO for writing
    fd = open("/tmp/myfifo", O_WRONLY);
    write(fd, message, sizeof(message));
    close(fd);

    return 0;
}

