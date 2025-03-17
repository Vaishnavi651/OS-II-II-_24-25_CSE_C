#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 100

struct message {
    long msg_type; // Message type
    char msg_text[MAX_TEXT]; // Message text
};

int main() {
    key_t key = ftok("msg_queue", 65); // Generate a unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create a message queue

    struct message msg;
    while (1) {
        printf("Enter message: ");
        fgets(msg.msg_text, MAX_TEXT, stdin);
        msg.msg_type = 1; // Set message type

        // Send message
        msgsnd(msgid, &msg, sizeof(msg), 0);
        printf("Message sent: %s", msg.msg_text);
    }

    // Cleanup (not reached in this example)
    msgctl(msgid, IPC_RMID, NULL); // Remove message queue
    return 0;
}
