#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgqueue.h"

int main() {
    int msg_id;
    struct msg_buffer message;
    msg_id = msgget(QUEUE_KEY, 0666);
    if (msg_id == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }
    if (msgrcv(msg_id, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv failed");
        exit(EXIT_FAILURE);
    }
    printf("Receiver: Received message - %s\n", message.msg_text);
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("msgctl failed");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Message queue deleted.\n");
    return 0;
}

