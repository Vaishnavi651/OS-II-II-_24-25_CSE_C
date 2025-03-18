//  Reader process(consumer)



#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of shared memory

int main() {
    key_t key;
    int shm_id;
    char *shm_ptr;

    // Generate the same unique key
    key = ftok("progfile", 65);  // Must match the key used by the writer

    // Access the shared memory segment
    shm_id = shmget(key, SHM_SIZE, 0666);

    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    // Attach the shared memory segment to the process's address space
    shm_ptr = (char *) shmat(shm_id, NULL, 0);
    if ((void *)shm_ptr == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }

    // Read the data from shared memory
    printf("Data read from shared memory: %s", shm_ptr);

    // Detach shared memory
    shmdt(shm_ptr);

    return 0;
}

