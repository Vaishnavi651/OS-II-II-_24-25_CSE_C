
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 1234  
int main() {
    int shmid;
    char *shm_ptr;

    
    shmid = shmget(KEY, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("Error creating shared memory");
        exit(EXIT_FAILURE);
    }

    
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)(-1)) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    
    strcpy(shm_ptr, "Hello from Shared Memory Writer!");
    printf("Writer: Message written to shared memory.\n");

    return 0;
}
