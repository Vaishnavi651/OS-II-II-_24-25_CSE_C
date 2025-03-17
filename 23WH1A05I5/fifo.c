#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
int main() {
    const char *fifo_name = "/tmp/my_fifo";
    const char *message = "Hello from the writer process!";
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        int fd = open(fifo_name, O_WRONLY);
        if (fd == -1) {
            perror("open for writing");
            return 1;
        }
        write(fd, message, sizeof(message));
        printf("Writer: Message sent to FIFO\n");
        close(fd);
        exit(0);
    }
    else {
        int fd = open(fifo_name, O_RDONLY);
        if (fd == -1) {
            perror("open for reading");
            return 1;
        }
        char buffer[128];
        read(fd, buffer, sizeof(buffer));
        printf("Reader: Received message Hello from writer Process");
        close(fd);
        unlink(fifo_name);
    }
    return 0;
}
