#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "/tmp/my_fifo";
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    int fifo_fd = open(fifo_name, O_WRONLY);
    if (fifo_fd == -1) {
        perror("open");
        return 1;
    }
    char *message = "Hello from the writer process!";
    write(fifo_fd, message, sizeof(message));
    printf("Data written to FIFO: %s\n", message);
    close(fifo_fd);
    return 0;
}
