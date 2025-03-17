#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    char message[] = "Hello from FIFO Writer!";

    // Ensure the FIFO file exists
    if (access(FIFO_PATH, F_OK) == -1) {
        if (mkfifo(FIFO_PATH, 0666) == -1) {
            perror("Error creating FIFO");
            exit(EXIT_FAILURE);
        }
    }

    // Open FIFO for writing
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Write message to FIFO
    write(fd, message, sizeof(message));
    printf("Writer: Message written to FIFO.\n");

    // Close the FIFO
    close(fd);
    return 0;
}

