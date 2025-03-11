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
    while (1) {
        
        item = rand() % 100;
        
        sem_wait(&empty);  
        sem_wait(&mutex);  
        
        buffer[in] = item;
        in = (in + 1) % buffer_size;
        printf("Producer produced item: %d\n", item);
        
        sem_post(&mutex);  
        sem_post(&full);   

        sleep(1);  
    }
    return NULL;
}


void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);  
        sem_wait(&mutex); 

        
        item = buffer[out];
        out = (out + 1) % buffer_size;
        printf("Consumer consumed item: %d\n", item);
        
        sem_post(&mutex);  
        sem_post(&empty); 

        sleep(1);  
    }
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

   
    sem_init(&mutex, 0, 1);   // Mutex to ensure mutual exclusion
    sem_init(&empty, 0, buffer_size); // Initially, all slots are empty
    sem_init(&full, 0, 0);     // Initially, no items are in the buffer

   
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

