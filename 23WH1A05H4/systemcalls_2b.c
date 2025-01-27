#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    printf("File opened successfully.\n");

    const char *data = "Hello, this is a test file!\n";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written < 0) {
        perror("write");
        close(fd);
        return 1;
    }
    printf("Data written to file.\n");


    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
        close(fd);
        return 1;
    }

    char buffer[256];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        perror("read");
        close(fd);
        return 1;
    }
    buffer[bytes_read] = '\0';
    printf("Data read from file:\n%s\n", buffer);

    struct stat file_stat;
    if (stat("example.txt", &file_stat) < 0) {
        perror("stat");
        close(fd);
        return 1;
    }
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("File permissions: %o\n", file_stat.st_mode & 0777);

    if (close(fd) < 0) {
        perror("close");
        return 1;
    }
    printf("File closed successfully.\n");

    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }
    printf("Directory opened successfully.\n");

    struct dirent *entry;
    printf("Directory entries:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    if (closedir(dir) < 0) {
        perror("closedir");
        return 1;
    }
    printf("Directory closed successfully.\n");

    return 0;
}
