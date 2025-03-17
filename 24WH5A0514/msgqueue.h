#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define QUEUE_KEY 1234  
#define MSG_SIZE 100
struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

#endif

