#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("file", 65);  // Generate unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // Get shared memory
    char *str = (char *)shmat(shmid, NULL, 0);  // Attach memory at OS-chosen address

    printf("Received from shared memory at address %p: %s", str, str);  // Print message

    shmdt(str);  // Detach from memory
    shmctl(shmid, IPC_RMID, NULL);  // Remove shared memory
    return 0;
}
