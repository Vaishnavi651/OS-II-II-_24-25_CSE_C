#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>  // For open() and O_WRONLY
#include <sys/types.h>
#include <sys/stat.h>  // For mkfifo()

#define FIFO_NAME "/tmp/my_fifo"  // Define the FIFO file name

int main() {
    int fifo_fd;
    char input[100];

    // Check if FIFO already exists, if not, create it
    if (access(FIFO_NAME, F_OK) == -1) {  // Check if FIFO doesn't exist
        if (mkfifo(FIFO_NAME, 0666) == -1) {  // Try to create the FIFO
            perror("Failed to create FIFO");
            exit(1);
        } else {
            printf("FIFO created successfully.\n");
        }
    } else {
        printf("FIFO already exists.\n");
    }

    // Open the FIFO for writing (blocks if the reader isn't ready)
    fifo_fd = open(FIFO_NAME, O_WRONLY);
    if (fifo_fd == -1) {
        perror("Failed to open FIFO for writing");
        exit(1);
    }

    // Continuously take input and write it to the FIFO
    while (1) {
        printf("Write a message to the child process: ");
        fgets(input, sizeof(input), stdin);  // Get input from the user

        // Write the input to the FIFO
        write(fifo_fd, input, sizeof(input));
    }

    close(fifo_fd);  // Close the FIFO after writing
    return 0;
}

