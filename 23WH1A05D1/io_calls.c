#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    // Open - Create a new file
    int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Write
    char *text = "Hello, System Calls!\n";
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written < 0) {
        perror("write");
        return 1;
    }

    // Seek
    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
        return 1;
    }

    // Read
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("read");
        return 1;
    }
    buffer[bytes_read] = '\0';
    printf("Read from file: %s", buffer);

    // Close
    if (close(fd) < 0) {
        perror("close");
        return 1;
    }

    // Stat
    struct stat file_stat;
    if (stat("test.txt", &file_stat) < 0) {
        perror("stat");
        return 1;
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

    // Directory operations
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    printf("\nDirectory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
