#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 10  

int *buffer;   
int bs;        
int in = 0, out = 0;
int x = 0;     
sem_t mutex, full, empty; 
void producer() {
    int empty_count;
    sem_getvalue(&empty, &empty_count); 

    if (empty_count == 0) {
        printf("\nBuffer is full! Cannot produce more items.");
        return;
    }

    sem_wait(&empty);
    sem_wait(&mutex);  

    buffer[in] = ++x;
    printf("\nProducer produced item %d", x);
    in = (in + 1) % bs;

    sem_post(&mutex); 
    sem_post(&full);
}


void consumer() {
    int full_count;
    sem_getvalue(&full, &full_count); 

    if (full_count == 0) {
        printf("\nNo items to consume!");
        return;
    }

    sem_wait(&full);  
    sem_wait(&mutex);

    printf("\nConsumer consumed item %d", buffer[out]);
    out = (out + 1) % bs;

    sem_post(&mutex);  
    sem_post(&empty);  
}

int main() {
    int choice;

    printf("Enter buffer size: ");
    scanf("%d", &bs);
    
    
    buffer = (int*)malloc(bs * sizeof(int));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, bs);

    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;

            case 2:
                consumer();
                break;

            case 3:
                printf("\nExiting...\n");
                free(buffer);
                sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }
    }

    return 0;
}




