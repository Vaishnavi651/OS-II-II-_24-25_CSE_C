#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

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

    printf("Enter message: ");
    fgets(shared_memory, SHM_SIZE, stdin);  
    printf("Data written to shared memory: %s\n", shared_memory);

    shmdt(shared_memory);

    return 0;
}

