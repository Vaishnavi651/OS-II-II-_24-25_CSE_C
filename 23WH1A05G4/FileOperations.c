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
    
    fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0664);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    const char *text = "Hello, World!";
    ssize_t bytesWritten = write(fd, text, strlen(text));
    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    
    lseek(fd, 0, SEEK_SET);
    
    ssize_t bytesRead = read(fd, buf, sizeof(buf) - 1);
    if (bytesRead >= 0) {
        buf[bytesRead] = '\0'; // Null terminate the string
        printf("Read from file: %s\n", buf);
    } else {
        perror("Error reading file");
    }
   
    close(fd);

    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    printf("Directory entries:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("Found entry: %s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
