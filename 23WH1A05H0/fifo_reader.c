#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>
int main() {
    int fd;
    char buffer[100];


    mkfifo("myfifo", 0666);

    while (1) {

        fd = open("myfifo", O_RDONLY);
        read(fd, buffer, sizeof(buffer));

        printf("Received: %s", buffer);
        close(fd);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    return 0;
}
