#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

int *buffer;
int buffer_size;
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

// Producer function
void *producer(void *param) {
    while (1) {
        int item;
        printf("\nEnter item to produce (or -1 to exit): ");
        scanf("%d", &item);

        if (item == -1) {
            printf("Producer exiting...\n");
            break;
        }

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % buffer_size;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

// Consumer function
void *consumer(void *param) {
    while (1) {
        char choice;
        printf("\nPress 'c' to consume or 'e' to exit: ");
        scanf(" %c", &choice);

        if (choice == 'e') {
            printf("Consumer exiting...\n");
            break;
        }

        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % buffer_size;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

// Main function
int main() {
    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);

    buffer = (int *)malloc(buffer_size * sizeof(int));

    sem_init(&empty, 0, buffer_size);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    printf("All operations completed.\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    free(buffer);

    return 0;
}
