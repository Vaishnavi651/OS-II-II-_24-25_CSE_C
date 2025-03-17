#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define KEY 1234  
int main() {
    int shmid;
    char *shm_ptr;


    shmid = shmget(KEY, 1024, 0666);
    if (shmid == -1) {
        perror("Error accessing shared memory");
        exit(EXIT_FAILURE);
    }

    
    shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)(-1)) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    
    printf("Reader: Received message: %s\n", shm_ptr);

    
    shmdt(shm_ptr);

    
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("Error removing shared memory");
        exit(EXIT_FAILURE);
    }

    printf("Reader: Shared memory deleted.\n");
    return 0;
}

