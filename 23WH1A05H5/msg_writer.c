#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>

#define MSGQ_KEY 1234 

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    int msgid;
    struct msg_buffer message;
    msgid = msgget(MSGQ_KEY, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    message.msg_type = 1;

    printf("Enter a message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
    message.msg_text[strcspn(message.msg_text, "\n")] = 0;  
    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Message sent: %s\n", message.msg_text);

    return 0;
}

