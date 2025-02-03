// Online C compiler to run C program online
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buff[100];
    ssize_t bytes_read; // To store the number of bytes read

    // File creation and writing
    fd = open("sample.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error has occurred!");
        return 1;
    }
    write(fd, "Hello\n", 6); // Corrected to 6 bytes for "Hello\n"
    close(fd);

    // Reading from the file
    fd = open("sample.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error occurred while opening the file for reading");
        return 1;
    }
    bytes_read = read(fd, buff, sizeof(buff) - 1); // Leave space for null terminator
    if (bytes_read == -1) {
        perror("Error occurred while reading the file");
        close(fd);
        return 1;
    }
    buff[bytes_read] = '\0'; // Null-terminate the string
    printf("Read from file: %s", buff);

    // Reposition the file pointer to the beginning
    off_t offset = lseek(fd, 0, SEEK_SET);
    if (offset == (off_t)-1) {
        perror("Error while seeking");
        close(fd);
        return 1;
    }
    close(fd); // Close after lseek

    // Getting file information
    struct stat fs;
    if (lstat("sample.txt", &fs) == -1) {
        perror("Error while retrieving file information");
        return 1;
    }
    printf("File size: %lld bytes\n", (long long)fs.st_size);

    // Listing directory contents
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error in opening directory");
        return 1;
    }
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);

    return 0;
} 
