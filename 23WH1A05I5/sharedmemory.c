// writer

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


//reader

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

//similar to fifo using 2 tabs file in terminal 

// create two files writer and reader => gcc write.c -o writer (OR) gcc read.c -o reader => ./writer (OR) ./sender (OR) ./reciever
