#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    int fd = open("sample.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }
    printf("File opened successfully with file descriptor: %d\n", fd);

    char *text = "Hello, this is a test write operation.\n";
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(fd);
        exit(1);
    }
    printf("Written %zd bytes to the file.\n", bytes_written);

    off_t offset = lseek(fd, 0, SEEK_SET);
    if (offset == -1) {
        perror("Error seeking in file");
        close(fd);
        exit(1);
    }
    printf("File pointer moved to position: %ld\n", (long)offset);

    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("Error reading from file");
        close(fd);
        exit(1);
    }
    buffer[bytes_read] = '\0';
    printf("Read %zd bytes: %s\n", bytes_read, buffer);

    struct stat file_stat;
    if (stat("sample.txt", &file_stat) == -1) {
        perror("Error getting file status");
        close(fd);
        exit(1);
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

    if (close(fd) == -1) {
        perror("Error closing file");
        exit(1);
    }
    printf("File closed successfully.\n");

    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        exit(1);
    }
    printf("Directory opened successfully.\n");

    struct dirent *entry;
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf(" - %s\n", entry->d_name);
    }

    if (closedir(dir) == -1) {
        perror("Error closing directory");
        exit(1);
    }
    printf("Directory closed successfully.\n");

    return 0;
}

