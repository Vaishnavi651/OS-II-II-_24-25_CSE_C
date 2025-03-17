#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "/tmp/my_fifo";
    int fifo_fd = open(fifo_name, O_RDONLY);
    if (fifo_fd == -1) {
        perror("open");
        return 1;
    }
    char buffer[128];
    read(fifo_fd, buffer, sizeof(buffer));
    printf("Data received from FIFO: %s\n", buffer);
    close(fifo_fd);
    return 0;
}
