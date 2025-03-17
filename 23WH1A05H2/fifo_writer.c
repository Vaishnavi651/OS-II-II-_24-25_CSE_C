#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>

#define QUEUE_NAME "/fifo_queue"
#define MAX_SIZE 1024

int main() {
    mqd_t mq;
    char message[MAX_SIZE];

    mq = mq_open(QUEUE_NAME, O_WRONLY | O_CREAT, 0644, NULL);
    if (mq == -1) {
        perror("Error creating queue");
        exit(1);
    }
    
    while (1) {
        printf("Enter message: ");
        fgets(message, MAX_SIZE, stdin);
        mq_send(mq, message, strlen(message), 0);
    }

    mq_close(mq);
    return 0;
}

