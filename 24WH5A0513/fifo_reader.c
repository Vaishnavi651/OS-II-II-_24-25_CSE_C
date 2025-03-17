#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    char buffer[100];

    // Ensure the FIFO file exists before opening
    if (access(FIFO_PATH, F_OK) == -1) {
        if (mkfifo(FIFO_PATH, 0666) == -1) {
            perror("Error creating FIFO");
            exit(EXIT_FAILURE);
        }
    }

    // Open FIFO for reading
    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read message from FIFO
    read(fd, buffer, sizeof(buffer));
    printf("Reader: Received message: %s\n", buffer);

    // Close the FIFO
    close(fd);

    // Remove the FIFO after reading
    unlink(FIFO_PATH);
    return 0;
}

