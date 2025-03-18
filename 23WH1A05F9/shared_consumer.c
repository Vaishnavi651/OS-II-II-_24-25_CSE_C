#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

#define SHM_SIZE 1024

int main() {
    key_t key = ftok("shmfile", 65); 
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT); 
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *shared_memory = (char*) shmat(shmid, NULL, 0);
    if (shared_memory == (char*) -1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Data read from shared memory: %s\n", shared_memory);

    shmdt(shared_memory);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

