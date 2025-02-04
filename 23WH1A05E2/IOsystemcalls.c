#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void my_open(const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }
    printf("Opened file '%s' with file descriptor: %d\n", filename, fd);
    
    // Write example data
    const char *text = "Hello, World!\n";
    write(fd, text, strlen(text));
    
    // Seek to the beginning of the file
    lseek(fd, 0, SEEK_SET);
    
    // Read example data back
    char buffer[50];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead >= 0) {
        buffer[bytesRead] = '\0';  // Null terminate the string
        printf("Read from file: %s", buffer);
    } else {
        perror("Error reading file");
    }

    // Get file status
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("Error getting file status");
    } else {
        printf("File size: %ld bytes\n", fileStat.st_size);
    }

    // Close the file
    close(fd);
    printf("Closed file descriptor: %d\n", fd);
}

void my_opendir(const char *dirname) {
    DIR *dir = opendir(dirname);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("Directory entry: %s\n", entry->d_name);
    }
    
    closedir(dir);
    printf("Closed directory: %s\n", dirname);
}

int main() {
    const char *filename = "example.txt";
    
    // Create/open the file and perform read/write operations
    my_open(filename);
    
    // List entries in the current directory
    my_opendir(".");

    return 0;
}
