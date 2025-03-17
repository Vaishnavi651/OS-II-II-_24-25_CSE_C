#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

#define MSGQ_KEY 1234  // Same key as writer

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct msg_buffer message;

    // Get message queue ID
    msgid = msgget(MSGQ_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    // Receive message (msg_type = 1 means we are waiting for type 1 messages)
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv failed");
        exit(1);
    }

    printf("Received: %s\n", message.msg_text);

    return 0;
}

