#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd;
    const char *content = "Hi..I am Dharani....\n";

    // Open the file for writing. If it doesn't exist, create it. 
    // O_WRONLY: open for writing, O_CREAT: create the file if it doesn't exist, O_TRUNC: truncate to 0 size if file exists
    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);  // S_IRUSR and S_IWUSR set permissions for the user

    if (fd < 0) {  // Check for error
        perror("Failed to open the file");
        exit(1);
    }

    // Write content to the file
    ssize_t bytes_written = write(fd, content, strlen(content));
    if (bytes_written < 0) {
        perror("Failed to write to the file");
        close(fd);
        exit(1);
    }

    printf("Successfully wrote %ld bytes to the file.\n", bytes_written);

    // Close the file
    close(fd);

    return 0;
}

