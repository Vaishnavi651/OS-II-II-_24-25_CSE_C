// writer process (producer)...

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024  // Size of shared memory

int main() {
    key_t key;
    int shm_id;
    char *shm_ptr;
    char input[100];

    // Generate a unique key
    key = ftok("progfile", 65); // Create a unique key based on file "progfile" and an integer

    // Create a shared memory segment
    shm_id = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);  // 0666 sets permissions to allow read and write for everyone

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

    printf("Enter a message: ");
    fgets(input, sizeof(input), stdin);

    // Copy input message to shared memory
    strncpy(shm_ptr, input, SHM_SIZE);

    printf("Data written to shared memory: %s", shm_ptr);

    // Wait for the reader to read the data (optional)
    printf("Press Enter to continue...");
    getchar();

    // Detach shared memory
    shmdt(shm_ptr);

    return 0;
}

