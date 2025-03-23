#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char msg[100];
    mkfifo("fifo_user1_to_user2", 0666);
    mkfifo("fifo_user2_to_user1", 0666);
    fd1 = open("fifo_user2_to_user1", O_RDONLY);
    if (fd1 == -1) {
        perror("Error opening FIFO (read)");
        exit(1);
    }

    fd2 = open("fifo_user1_to_user2", O_WRONLY);
    if (fd2 == -1) {
        perror("Error opening FIFO (write)");
        exit(1);
    }

    while (1) {
        read(fd1, msg, sizeof(msg));
        printf("User1 received: %s\n", msg);

        printf("User1: ");
        scanf("%[^\n]", msg);
        getchar();

        write(fd2, msg, strlen(msg) + 1);
    }

    close(fd1);
    close(fd2);

    return 0;
}
