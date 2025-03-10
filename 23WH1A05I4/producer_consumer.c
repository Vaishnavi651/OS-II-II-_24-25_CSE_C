#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mutex = 1;  
int full = 0;   
int empty = 0;  
int item = 0;   
int buffer_size = 0; 

void wait(int *s) {
    (*s)--;
    if (*s < 0) {
        printf("Waiting...\n");
        sleep(1);  
    }
}

void signal(int *s) {
    (*s)++;
    if (*s <= 0) {
        printf("Signaling...\n");
    }
}

void producer() {
    int nextp = item + 1;  
    wait(&empty);
    wait(&mutex);
    item = nextp;
    printf("Producer produces item %d\n", item);

    signal(&mutex);
    signal(&full);
}

void consumer() {
    wait(&full);
    wait(&mutex);

    printf("Consumer consumes item %d\n", item);
    int prevItem=item-1;
    item = prevItem;  
    signal(&mutex);
    signal(&empty);
}

int main() {
    printf("Enter the buffer size: ");
    scanf("%d", &buffer_size);

    empty = buffer_size;
    
    int n;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                if (mutex == 1 && empty != 0) {
                    producer();
                } else {
                    printf("Buffer is full!\n");
                }
                break;

            case 2:
                if (mutex == 1 && full != 0) {
                    consumer();
                } else {
                    printf("Buffer is empty!\n");
                }
                break;

            case 3:
                printf("Exiting the program\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

