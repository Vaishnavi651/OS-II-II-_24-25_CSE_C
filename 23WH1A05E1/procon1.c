#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t full, empty;
pthread_mutex_t mutex;

int buffer_size, x = 0; 

void *producer(void *arg) {
    sem_wait(&empty);               
    pthread_mutex_lock(&mutex);      

    x++;
    printf("\nProducer produces item %d", x);

    if (x == buffer_size) {
        printf("\nBuffer is now full! No more items can be produced.");
    }

    pthread_mutex_unlock(&mutex);    
    sem_post(&full);               

    return NULL;
}


void *consumer(void *arg) {
    sem_wait(&full);                
    pthread_mutex_lock(&mutex);       

    printf("\nConsumer consumes item %d", x);
    x--;

    pthread_mutex_unlock(&mutex);   
    sem_post(&empty);                 

    return NULL;
}

int main() {
    int choice;
    
    printf("Enter buffer size: ");
    scanf("%d", &buffer_size);
    
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, buffer_size);
    pthread_mutex_init(&mutex, NULL);

    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        pthread_t tid;
        switch (choice) {
            case 1:
                if (x < buffer_size) {
                    pthread_create(&tid, NULL, producer, NULL);
                    pthread_join(tid, NULL);
                } else {
                    printf("\nBuffer is full! Cannot produce more items.");
                }
                break;
            case 2:
                if (x > 0) {
                    pthread_create(&tid, NULL, consumer, NULL);
                    pthread_join(tid, NULL);
                } else {
                    printf("\nBuffer is empty! Cannot consume.");
                }
                break;
            case 3:
               
                sem_destroy(&full);
                sem_destroy(&empty);
                pthread_mutex_destroy(&mutex);
                exit(0);
            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.");
        }
    }

    return 0;

}

