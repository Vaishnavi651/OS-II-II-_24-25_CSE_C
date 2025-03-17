#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("file", 65);  
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  
    char *str = (char *)shmat(shmid, NULL, 0); 
     
    printf("Enter message: ");
    fgets(str, 1024, stdin);  

    printf("Message written to shared memory at address: %p\n", str);

    shmdt(str);  
    return 0;
}
