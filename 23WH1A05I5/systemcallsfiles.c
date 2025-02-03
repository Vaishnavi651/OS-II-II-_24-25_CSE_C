#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd;
    char buffer[100];
    
    // Open file for writing (Create if doesn't exist, truncate to empty if exists)
    fd = open("test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("File opening failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  
        // Parent Process
        char *data = "Hello from Parent!\n";
        write(fd, data, 19);  // Write data to file
        close(fd);  // Close the file in the parent
        wait(NULL); // Wait for child to finish
        printf("Parent process done.\n");

    } else {  
        // Child Process
        sleep(1); // Ensure parent writes before child reads

        fd = open("test.txt", O_RDONLY); // Reopen file for reading
        if (fd < 0) {
            perror("File open failed in child");
            exit(1);
        }

        read(fd, buffer, sizeof(buffer));  // Read from file
        printf("Child read: %s", buffer); // Print content
        close(fd);
    }

    return 0;
}
