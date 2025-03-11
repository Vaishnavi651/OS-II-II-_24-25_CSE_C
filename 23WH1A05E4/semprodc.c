#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 10

// Buffer size, full and empty slots
int buffer[MAX_BUFFER_SIZE];
int buffer_size;
int in = 0, out = 0;

// Semaphores
sem_t mutex, empty, full;

// Producer function
void* producer(void* arg) {
    int item;
    while (1) {
        // Produce an item (simulate it by incrementing item number)
        item = rand() % 100;
        
        sem_wait(&empty);  // Wait for empty space in the buffer
        sem_wait(&mutex);  // Enter critical section
        
        // Add item to buffer
        buffer[in] = item;
        in = (in + 1) % buffer_size;
        printf("Producer produced item: %d\n", item);
        
        sem_post(&mutex);  // Leave critical section
        sem_post(&full);   // Signal that there is an item in the buffer

        sleep(1);  // Sleep to simulate time taken to produce
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);  // Wait for an item to consume
        sem_wait(&mutex); // Enter critical section

        // Consume an item from the buffer
        item = buffer[out];
        out = (out + 1) % buffer_size;
        printf("Consumer consumed item: %d\n", item);
        
        sem_post(&mutex);  // Leave critical section
        sem_post(&empty);  // Signal that there is empty space in the buffer

        sleep(1);  // Sleep to simulate time taken to consume
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;
    int choice;
    
    // Initialize buffer size
    printf("Enter the buffer size: ");
    scanf("%d", &buffer_size);
    
    // Check for buffer size constraints
    if (buffer_size <= 0 || buffer_size > MAX_BUFFER_SIZE) {
        printf("Invalid buffer size. Please choose a value between 1 and %d.\n", MAX_BUFFER_SIZE);
        return -1;
    }

    // Initialize semaphores
    sem_init(&mutex, 0, 1);   // Mutex to ensure mutual exclusion
    sem_init(&empty, 0, buffer_size); // Initially, all slots are empty
    sem_init(&full, 0, 0);     // Initially, no items are in the buffer

    // Create threads for producer and consumer
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for threads to finish (this won't happen in this case, since the loops are infinite)
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

