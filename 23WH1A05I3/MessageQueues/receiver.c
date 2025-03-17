#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("file", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;

    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
    printf("Received: %s", message.msg_text);
    
   //to remove the message queue:
    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}

