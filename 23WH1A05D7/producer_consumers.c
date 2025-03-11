#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 5
#define PRODUCER_COUNT 5
#define CONSUMER_COUNT 5

struct buffer {
    int data[BUFFER_SIZE];
    int in;
    int out;
};

void P(int sem_id) {
    struct sembuf sb = {0, -1, 0};
    semop(sem_id, &sb, 1);
}

void V(int sem_id) {
    struct sembuf sb = {0, 1, 0};
    semop(sem_id, &sb, 1);
}

int main() {
    key_t shm_key = 1234;
    key_t sem_key = 5678;
    
    int shm_id = shmget(shm_key, sizeof(struct buffer), IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }
    
    struct buffer *buf = shmat(shm_id, NULL, 0);
    if ((void*)buf == (void*)-1) {
        perror("shmat");
        exit(1);
    }
    
    int sem_id = semget(sem_key, 3, IPC_CREAT | 0666);
    if (sem_id < 0) {
        perror("semget");
        exit(1);
    }
    
    semctl(sem_id, 0, SETVAL, BUFFER_SIZE);
    semctl(sem_id, 1, SETVAL, 0);
    semctl(sem_id, 2, SETVAL, 1);
    
    buf->in = 0;
    buf->out = 0;
    
    pid_t pid;
    
    if ((pid = fork()) == 0) {
        for (int i = 0; i < PRODUCER_COUNT; i++) {
            P(sem_id);
            P(sem_id + 2);
            buf->data[buf->in] = i + 1;
            printf("Produced: %d\n", buf->data[buf->in]);
            buf->in = (buf->in + 1) % BUFFER_SIZE;
            V(sem_id + 2);
            V(sem_id + 1);
            sleep(1);
        }
        exit(0);
    }
    
    if ((pid = fork()) == 0) {
        for (int i = 0; i < CONSUMER_COUNT; i++) {
            P(sem_id + 1);
            P(sem_id + 2);
            int item = buf->data[buf->out];
            printf("Consumed: %d\n", item);
            buf->out = (buf->out + 1) % BUFFER_SIZE;
            V(sem_id + 2);
            V(sem_id);
            sleep(1);
        }
        exit(0);
    }
    
    wait(NULL);
    wait(NULL);
    
    shmctl(shm_id, IPC_RMID, NULL);
    semctl(sem_id, 0, IPC_RMID);
    
    return 0;
}

