#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define BUFFER_SIZE 100

struct msg_buffer {
    long msg_type;
    char msg_text[BUFFER_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    while (1) {
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
            perror("msgrcv failed");
            exit(1);
        }

        printf("Received from Writer: %s", message.msg_text);

        if (strncmp(message.msg_text, "exit", 4) == 0) {
            break;
        }

        message.msg_type = 2;
        printf("Enter reply: ");
        fgets(message.msg_text, BUFFER_SIZE, stdin);

        if (strncmp(message.msg_text, "exit", 4) == 0) {
            msgsnd(msgid, &message, sizeof(message.msg_text), 0);
            break;
        }

        if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
            perror("msgsnd failed");
            exit(1);
        }
    }

    return 0;
}
