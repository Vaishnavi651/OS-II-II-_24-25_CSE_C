#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void printBuffer(int buffer[], int bufsize, int in, int out) {
    printf("\nBuffer: ");
    if (in == out) {
        printf("Empty");
    } else {
        int index = out;
        while (index != in) {
            printf("%d ", buffer[index]);
            index = (index + 1) % bufsize;
        }
    }
    printf("\n");
}

void *producer(void *arg) {
    int *buffer = (int *)arg;
    int bufsize = buffer[0];
    int in = buffer[1];
    int out = buffer[2];
    int produce;

    while (1) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        printf("\nEnter the value to produce: ");
        scanf("%d", &produce);
        buffer[in] = produce;
        in = (in + 1) % bufsize;

        printf("\nProducer produced: %d", produce);
        printBuffer(buffer, bufsize, in, out);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *arg) {
    int *buffer = (int *)arg;
    int bufsize = buffer[0];
    int in = buffer[1];
    int out = buffer[2];
    int consume;

    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        consume = buffer[out];
        out = (out + 1) % bufsize;

        printf("\nConsumer consumed: %d", consume);
        printBuffer(buffer, bufsize, in, out);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main() {
    int bufsize, in, out, choice;
    int *buffer;

    printf("Enter buffer size: ");
    scanf("%d", &bufsize);

    buffer = (int *)malloc((bufsize + 3) * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    buffer[0] = bufsize;
    in = 1;
    out = 2;
    buffer[in] = buffer[out] = 0;

    sem_init(&empty, 0, bufsize);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t producer_thread, consumer_thread;

    pthread_create(&producer_thread, NULL, producer, buffer);
    pthread_create(&consumer_thread, NULL, consumer, buffer);

    do {
        printf("\nMenu:\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sem_wait(&empty);
                pthread_mutex_lock(&mutex);
                printf("\nEnter the value to produce: ");
                int produce;
                scanf("%d", &produce);
                buffer[in] = produce;
                in = (in + 1) % bufsize;
                printf("\nProducer produced: %d", produce);
                printBuffer(buffer, bufsize, in, out);
                pthread_mutex_unlock(&mutex);
                sem_post(&full);
                break;

            case 2:
                sem_wait(&full);
                pthread_mutex_lock(&mutex);
                int consume = buffer[out];
                out = (out + 1) % bufsize;
                printf("\nConsumer consumed: %d", consume);
                printBuffer(buffer, bufsize, in, out);
                pthread_mutex_unlock(&mutex);
                sem_post(&empty);
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice, please try again.");
                break;
        }
    } while (choice != 3);

    pthread_cancel(producer_thread);
    pthread_cancel(consumer_thread);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    free(buffer);
    return 0;
}
