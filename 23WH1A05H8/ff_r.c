#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo"; // FIFO path
    char arr[100];

    while (1) {
        // Open FIFO for read only
        fd = open(myfifo, O_RDONLY);
        
        // Read from FIFO
        read(fd, arr, sizeof(arr));
        
        // Print the read message
        printf("User  2: %s\n", arr);
        close(fd);

        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);
        
        // Send a response back
        printf("User  2 (response): ");
        fgets(arr, sizeof(arr), stdin);
        write(fd, arr, strlen(arr) + 1);
        close(fd);
    }

    return 0;
}
