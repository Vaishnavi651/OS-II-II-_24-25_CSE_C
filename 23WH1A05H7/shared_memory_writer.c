#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024  
int main() {
    key_t key = ftok("shmfile", 65);  
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);  
    char *str = (char*) shmat(shmid, (void*)0, 0);  

    printf("Enter message to write in shared memory: ");
    fgets(str, SHM_SIZE, stdin);  
    printf("Data written in memory: %s\n", str);
    shmdt(str);  // Detach shared memory
    return 0;
}
