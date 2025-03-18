#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define SHM_SIZE 1024  
int main() {
    key_t key;
    int shmid;
    char *shm_addr;
    key = ftok("shmfile", 65);
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if (shm_addr == (char *)(-1)) {
        perror("shmat failed");
        exit(1);
    }
    printf("Enter a message: ");
    fgets(shm_addr, SHM_SIZE, stdin);
    shm_addr[strcspn(shm_addr, "\n")] = 0; 
    printf("Data written to shared memory: %s\n", shm_addr);
    shmdt(shm_addr);
    return 0;
}
