// read

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    int fd;
    char buffer[100];
    fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(1);
    }
    read(fd, buffer, sizeof(buffer));
    printf("Reader: Received message: %s\n", buffer);
    close(fd);
    return 0;
}

// write

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    int fd;
    char msg[] = "Hello from Writer Process";
    fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
        perror("Error opening FIFO");
        exit(1);
    }
    write(fd, msg, strlen(msg) + 1);
    printf("Writer: Message sent to FIFO\n");
    close(fd);
    return 0;
}

// in two different terminal tabs do it simultaneously

// in first one, write writer code i.e gedit write.c => mkfifo myfifo => gcc write.c -o writer => ./writer

// in second one, write reader code i.e gedit read.c => mkfifo myfifo => gcc read.c -o reader => ./reader

// you'll get the following output for ./writer "Writer: Message sent to FIFO"

// you'll get the following output for ./reader "Reader: Received message: Hello from Writer Process"
