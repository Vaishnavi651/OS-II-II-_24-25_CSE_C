#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }
    int msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }
    struct msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello from the writer process!");
    if (msgsnd(msgid, &message, sizeof(message), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Data sent to message queue: %s\n", message.msg_text);

    return 0;
}
