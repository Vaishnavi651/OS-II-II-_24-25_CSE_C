#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_NAME "/fifo_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t mq;
    char buffer[MAX_SIZE];

    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == -1) {
        perror("Error opening queue");
        exit(1);
    }

    while (1) {
        ssize_t bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        if (bytes_read >= 0) {
            buffer[bytes_read] = '\0';
            printf("Received: %s\n", buffer);
        } else {
            perror("Error receiving message");
        }
    }

    mq_close(mq);
    return 0;
}
