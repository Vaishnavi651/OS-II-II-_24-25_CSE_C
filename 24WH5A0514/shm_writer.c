#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_common.h"

int main() {
    int shm_id;
    char *shared_memory;
    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666 | IPC_CREAT);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }
    shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    strcpy(shared_memory, "Hello from the writer process!");
    printf("Writer: Message written to shared memory.\n");
    shmdt(shared_memory);

    return 0;
}

