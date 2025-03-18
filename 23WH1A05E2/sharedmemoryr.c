#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("file", 65); 
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  
    char *str = (char *)shmat(shmid, NULL, 0);  
    printf("Received from shared memory at address %p: %s", str, str);  
    shmdt(str); 
    shmctl(shmid, IPC_RMID, NULL); 
    return 0;
}
