// sender.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
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
    printf("Enter a message to send: ");
    fgets(message.msg_text, sizeof(message.msg_text), stdin);
  
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0';

    message.msg_type = 1;

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Sender: Message sent -> %s\n", message.msg_text);
   

    return 0;
}


