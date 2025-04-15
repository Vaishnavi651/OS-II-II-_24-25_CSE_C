#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t empty, full, mutex;
int *buffer; 
int in = 0, out = 0;
int BUFFER_SIZE;

void produce_item() {
    int item = rand() % 100;

    if (sem_trywait(&empty) != 0) {
        printf("Buffer is full. Cannot produce.\n");
        return;
    }

    sem_wait(&mutex);

    printf("Producer entering critical section\n");
    buffer[in] = item;
    printf("Produced: %d (Stored at index %d)\n", item, in);
    in = (in + 1) % BUFFER_SIZE;
    printf("Producer exiting critical section\n");

    sem_post(&mutex);
    sem_post(&full);
}

void consume_item() {
    if (sem_trywait(&full) != 0) {
        printf("Buffer is empty. Cannot consume.\n");
        return;
    }

    sem_wait(&mutex);

    printf("Consumer entering critical section\n");
    int item = buffer[out];
    printf("Consumed: %d (Taken from index %d)\n", item, out);
    out = (out + 1) % BUFFER_SIZE;
    printf("Consumer exiting critical section\n");

    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    pthread_t prod_thread, cons_thread;

    printf("Enter the buffer size: ");
    scanf("%d", &BUFFER_SIZE);

    buffer = (int *)malloc(BUFFER_SIZE * sizeof(int)); 
    if(buffer == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    int choice;
    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                produce_item();
                break;
            case 2:
                consume_item();
                break;
            case 3:
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&mutex);
                free(buffer); 
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
        sleep(1);
    }

    return 0;
}
