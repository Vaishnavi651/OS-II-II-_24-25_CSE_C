#include <stdio.h> 
#include <stdlib.h>
#include <sys/stat.h>// used for stat like: struct stat , fileStat
#include <fcntl.h> //provides constants like O+RDWR,O_CRET
#include <dirent.h>//provides functions and directories for directories
#include <unistd.h>
#include <string.h>//for length of text

int main() {
    char buffer[100];
    int fd, bytesRead;

    // Open the file in read-write mode, create it if it doesn't exist
    fd = open("testfile.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    // Write some text to the file
    char *text = "Hello, This is a test file";
    write(fd, text, strlen(text)); //instead of strlen(text) we can also use the size fo text also.

    // Move the file pointer to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read the contents of the file
    bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Error reading file");
        close(fd);//close the file
        return 1;
    }

    // Null-terminate the buffer and print the file contents
    buffer[bytesRead] = '\0';
    printf("File contents are: %s\n", buffer);

    // Get file statistics
    struct stat fileStat;
    if (stat("testfile.txt", &fileStat) == -1) {
        perror("Error getting file stats");
    } else {
        printf("File size is: %ld bytes\n", fileStat.st_size);
        printf("File permissions: %o\n", fileStat.st_mode & 0777);
    }

    // Close the file
    close(fd);

    // Open the current directory
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening the directory");
        return 1;
    }

    // List all files in the current directory
    printf("Files in current directory are:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    return 0;
}
