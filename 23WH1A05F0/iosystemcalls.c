#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 1024

int main() {
    int fd = open("testfile.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    const char *data = "Hello, World!\n";
    if (write(fd, data, 14) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);
    char buffer[BUF_SIZE];
    ssize_t bytesRead = read(fd, buffer, BUF_SIZE);
    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }
    buffer[bytesRead] = '\0';
    printf("File content: %s\n", buffer);

    struct stat fileStat;
    if (stat("testfile.txt", &fileStat) == -1) {
        perror("Error getting file stats");
        close(fd);
        return 1;
    }
    printf("File size: %ld bytes\n", fileStat.st_size);

    close(fd);

    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("File: %s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
