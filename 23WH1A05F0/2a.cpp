#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buf[100];
   
    fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        printf("Error\n");
        return 1;
    }
    write(fd, "Hello, World!\n", 14);
    close(fd);
   
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error occurred");
        return 1;
    }
    read(fd, buf, sizeof(buf));
    printf("Read from file: %s\n", buf);
    close(fd);
   
    off_t offset = lseek(fd, 0, SEEK_SET);
    if (offset == (off_t) -1) {
        perror("Error seeking");
        return 1;
    }
   
    struct stat fs;
    if (stat("example.txt", &fs) == -1) {
        perror("Error");
        return 1;
    }
    printf("File size: %lld bytes\n", (long long) fs.st_size);
   
    DIR *dir;
    struct dirent *entry;
   
    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening");
        return 1;
    }
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
   
    return 0;
}
