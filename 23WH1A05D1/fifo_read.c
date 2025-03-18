#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  // For open() and O_RDONLY
#include <sys/types.h>
#include <sys/stat.h>  // For mkfifo()

#define FIFO_NAME "/tmp/my_fifo"  // Define the FIFO file name

int main() {
    int fifo_fd;
    char buffer[100];

    // Open the FIFO for reading (blocks if no data is available)
    fifo_fd = open(FIFO_NAME, O_RDONLY);
    if (fifo_fd == -1) {
        perror("Failed to open FIFO for reading");
        exit(1);
    }

    // Continuously read from the FIFO and display the message
    while (1) {
        // Read from the FIFO
        ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer));
        if (bytes_read > 0) {
            printf("Received message: %s", buffer);  // Display the received message
        } else if (bytes_read == 0) {
            // If the writer closes the FIFO, exit
            printf("Writer closed the FIFO.\n");
            break;
        } else {
            perror("Error while reading from FIFO");
            exit(1);
        }
    }

    close(fifo_fd);  // Close the FIFO after reading
    return 0;
}

