#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    
    int fd;
    char buf[100];
    
    // 1. open: Create or open a file with permissions 0664
    fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0664);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // 2. write: Write to the file
    const char *text = "Hello, World!";
    ssize_t bytesWritten = write(fd, text, strlen(text));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    
    // 3. lseek: Move the file pointer to the beginning
    lseek(fd, 0, SEEK_SET);
    
    // 4. read: Read from the file
    ssize_t bytesRead = read(fd, buf, sizeof(buf) - 1);
    if (bytesRead >= 0) {
        buf[bytesRead] = '\0'; // Null terminate the string
        printf("Read from file: %s\n", buf);
    } else {
        perror("Error reading file");
    }
    
    // 5. close: Close the file
    close(fd);

    // Directory operations
    DIR *dir;
    struct dirent *entry;

    // 6. opendir: Open a directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    // 7. readdir: Read entries in the directory
    printf("Directory entries:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("Found entry: %s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
