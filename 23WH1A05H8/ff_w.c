#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo"; // FIFO path

    // Create the named FIFO (named pipe)
    mkfifo(myfifo, 0666);

    char arr[100];
    while (1) {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
        
        // Take input from user
        printf("User  1: "); // Prompt for User 1
        fgets(arr, sizeof(arr), stdin);
        
        // Write the input string to FIFO
        write(fd, arr, strlen(arr) + 1);
        close(fd);
    }

    return 0;
}
