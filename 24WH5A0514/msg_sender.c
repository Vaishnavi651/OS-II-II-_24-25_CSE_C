#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msgqueue.h"

int main() {
    int msg_id;
    struct msg_buffer message;
    msg_id = msgget(QUEUE_KEY, 0666 | IPC_CREAT);
    if (msg_id == -1) {
        perror("msgget failed");
        exit(EXIT_FAILURE);
    }
    message.msg_type = 1; 
    strcpy(message.msg_text, "Hello from the sender!");
    if (msgsnd(msg_id, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(EXIT_FAILURE);
    }
    printf("Sender: Message sent.\n");
    return 0;
}

