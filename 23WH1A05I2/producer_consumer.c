#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5  

int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;
int x = 0;
int buffer[BUFFER_SIZE]; 

void producer() {
    --mutex;
    buffer[x] = x + 1;  
    ++full;
    --empty;
    printf("\nProducer produces item %d", buffer[x]);
    x++;
    ++mutex;
}

void consumer() {
    --mutex;
    printf("\nConsumer consumes item %d", buffer[x - 1]);
    x--;
    --full;
    ++empty;
    ++mutex;
}

int main() {
    int choice;

    while (1) {
        printf("\nPress \n 1-to Produce \n 2-to Consume \n 3-to Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1 && empty != 0) {
                    producer();
                } 
                else {
                    printf("\nBuffer is full\n");
                }
                break;
            case 2:
                if (mutex == 1 && full != 0) {
                    consumer();
                } 
                else {
                    printf("\nBuffer is empty\n");
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
}
