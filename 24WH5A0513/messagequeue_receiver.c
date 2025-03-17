#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define KEY 1234  
struct msg_buffer {
    long mtype;
    char mtext[100];
};

int main() {
    int msgid;
    struct msg_buffer message;

    
    msgid = msgget(KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("Error getting message queue");
        exit(EXIT_FAILURE);
    }

    
    if (msgrcv(msgid, &message, sizeof(message.mtext), 1, 0) == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Received message: %s\n", message.mtext);

    
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("Error removing message queue");
        exit(EXIT_FAILURE);
    }

    printf("Receiver: Message queue deleted.\n");
    return 0;
}

