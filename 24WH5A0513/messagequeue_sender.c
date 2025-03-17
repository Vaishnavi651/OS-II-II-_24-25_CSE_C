#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

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
        perror("Error creating message queue");
        exit(EXIT_FAILURE);
    }


    message.mtype = 1;  
    strcpy(message.mtext, "Hello from Message Queue Sender!");

 
    if (msgsnd(msgid, &message, sizeof(message.mtext), 0) == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    printf("Sender: Message sent successfully.\n");
    return 0;
}

