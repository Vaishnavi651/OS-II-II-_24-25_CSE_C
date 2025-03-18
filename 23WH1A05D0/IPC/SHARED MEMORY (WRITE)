#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  // Shared memory size

int main() {
    key_t key;
    int shmid;
    char *shm_addr;

    // Generate a unique key
    key = ftok("shmfile", 65);
    
    // Create shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Attach shared memory segment
    shm_addr = (char *) shmat(shmid, NULL, 0);
    if (shm_addr == (char *)(-1)) {
        perror("shmat failed");
        exit(1);
    }

    // Write to shared memory
    printf("Enter a message: ");
    fgets(shm_addr, SHM_SIZE, stdin);
    shm_addr[strcspn(shm_addr, "\n")] = 0; // Remove newline

    printf("Data written to shared memory: %s\n", shm_addr);

    // Detach from shared memory
    shmdt(shm_addr);

    return 0;
}
