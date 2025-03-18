#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MQ_NAME "/my_queue"        // Name of the message queue
#define MAX_MSG_SIZE 128          // Max size of a message
#define MAX_MSG_COUNT 10          // Max number of messages in the queue

int main() {
    mqd_t mq;
    char buffer[MAX_MSG_SIZE];
    struct mq_attr attr;

    // Set attributes for the message queue
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MSG_COUNT;   // Max number of messages
    attr.mq_msgsize = MAX_MSG_SIZE;   // Max size of a message
    attr.mq_curmsgs = 0;

    // Open or create a message queue with the specified attributes
    mq = mq_open(MQ_NAME, O_CREAT | O_RDWR, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    // Send a message to the queue
    const char *message = "Hello from sender!";
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message);

    // Receive a message from the queue
    if (mq_receive(mq, buffer, MAX_MSG_SIZE, NULL) == -1) {
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    // Close the queue
    if (mq_close(mq) == -1) {
        perror("mq_close");
        exit(EXIT_FAILURE);
    }

    // Unlink the message queue (remove it from the system)
    if (mq_unlink(MQ_NAME) == -1) {
        perror("mq_unlink");
        exit(EXIT_FAILURE);
    }

    return 0;
}

 
