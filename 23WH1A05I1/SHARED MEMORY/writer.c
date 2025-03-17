//writer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("file", 65);  // Generate unique key
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // Create shared memory
    char *str = (char *)shmat(shmid, NULL, 0);  // Attach memory at OS-chosen address

    printf("Enter message: ");
    fgets(str, 1024, stdin);  // Get user input

    printf("Message written to shared memory at address: %p\n", str);

    shmdt(str);  // Detach from memory
    return 0;
}
