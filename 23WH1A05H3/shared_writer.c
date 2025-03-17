#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("progfile", 65);
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    char *shm_ptr = (char*) shmat(shmid, NULL, 0);
    if (shm_ptr == (char*) -1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Enter a message: ");
    fgets(shm_ptr, 1024, stdin);

    printf("Data written to shared memory: %s\n", shm_ptr);

    return 0;
}
