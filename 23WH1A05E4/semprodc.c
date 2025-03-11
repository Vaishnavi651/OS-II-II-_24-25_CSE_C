#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 10

int buffer[MAX_BUFFER_SIZE];
int buffer_size;
int in = 0, out = 0;

sem_t mutex, empty, full;

void* producer(void* arg) {
    int item;
    item = rand() % 100;
    sem_wait(&empty);
    sem_wait(&mutex);
    buffer[in] = item;
    in = (in + 1) % buffer_size;
    printf("Producer produced item: %d\n", item);
    sem_post(&mutex);
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg) {
    int item;
    sem_wait(&full);
    sem_wait(&mutex);
    item = buffer[out];
    out = (out + 1) % buffer_size;
    printf("Consumer consumed item: %d\n", item);
    sem_post(&mutex);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    int choice;

    printf("Enter the buffer size: ");
    scanf("%d", &buffer_size);

    if (buffer_size <= 0 || buffer_size > MAX_BUFFER_SIZE) {
        printf("Invalid buffer size. Please choose a value between 1 and %d.\n", MAX_BUFFER_SIZE);
        return -1;
    }

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, buffer_size);
    sem_init(&full, 0, 0);

    while (1) {
        printf("\nSelect an action:\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&prod_thread, NULL, producer, NULL);
                pthread_join(prod_thread, NULL);
                break;
            case 2:
                pthread_create(&cons_thread, NULL, consumer, NULL);
                pthread_join(cons_thread, NULL);
                break;
            case 3:
                printf("Exiting program.\n");
                sem_destroy(&mutex);
                sem_destroy(&empty);
                sem_destroy(&full);
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}


