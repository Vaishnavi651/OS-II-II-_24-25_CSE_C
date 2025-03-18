#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_SIZE 1024  
int main() {
    key_t key;
    int shmid;
    char *shm_addr;
    key = ftok("shmfile", 65);
    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if (shm_addr == (char *)(-1)) {
        perror("shmat failed");
        exit(1);
    }
    printf("Data read from shared memory: %s\n", shm_addr);
    shmdt(shm_addr);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
