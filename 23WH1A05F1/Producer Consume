#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

int *buffer;
int buffer_size, total_operations;
int in = 0, out = 0, produced_count = 0, consumed_count = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *param) {
    while (produced_count < total_operations) {
        int item = rand() % 100; // Random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        buffer[in] = item;
        produced_count++;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % buffer_size;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        
        sleep(1);
    }
    return NULL;
}

void *consumer(void *param) {
    while (consumed_count < total_operations) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        int item = buffer[out];
        consumed_count++;
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % buffer_size;
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        
        sleep(1);
    }
    return NULL;
}

int main() {
    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);
    
    printf("Enter number of items to produce/consume: ");
    scanf("%d", &total_operations);

    buffer = (int *)malloc(buffer_size * sizeof(int));
    
    sem_init(&empty, 0, buffer_size);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    pthread_t producer_thread, consumer_thread;
    
    char choice;
    printf("Start producer or consumer first? (p/c): ");
    scanf(" %c", &choice);
    
    if (choice == 'p') {
        pthread_create(&producer_thread, NULL, producer, NULL);
        sleep(1); 
        pthread_create(&consumer_thread, NULL, consumer, NULL);
    } else if (choice == 'c') {
        printf("Buffer is empty, waiting for producer...\n");
        pthread_create(&consumer_thread, NULL, consumer, NULL);
        sleep(1);
        pthread_create(&producer_thread, NULL, producer, NULL);
    }

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    printf("All operations completed.\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    free(buffer);
    
    return 0;
}
