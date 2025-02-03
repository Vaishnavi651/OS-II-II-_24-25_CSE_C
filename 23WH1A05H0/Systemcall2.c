#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char buffer[100];

    fd = open("myfile.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    const char *text = "Hello, this is a simple file operation.\n";
    write(fd, text, strlen(text));
    printf("Data written to file.\n");

    lseek(fd, 0, SEEK_SET);

    int bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytesRead] = '\0';
    printf("Read from file: %s", buffer);

    close(fd);
    printf("File closed.\n");

    return 0;
}
