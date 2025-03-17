writer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[100];

    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);

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



reader


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


	
writer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd;
    char msg[100];

    printf("Enter a message: ");
    fgets(msg, sizeof(msg), stdin);

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



reader


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


	
