#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shm_common.h"

int main() {
    int shm_id;
    char *shared_memory;
    shm_id = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(EXIT_FAILURE);
    }
    shared_memory = (char *)shmat(shm_id, NULL, 0);
    if (shared_memory == (char *)-1) {
        perror("shmat failed");
        exit(EXIT_FAILURE);
    }
    printf("Reader: Received message - %s\n", shared_memory);
    shmdt(shared_memory);
    shmctl(shm_id, IPC_RMID, NULL);
    printf("Reader: Shared memory deleted.\n");

    return 0;
}

