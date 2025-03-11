#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mutex = 1;
int empty;
int full = 0;
int buffer[10];
int in = 0;
int out = 0;

void producer() {
    int item;
    printf("Enter item to produce: ");
    scanf("%d", &item);

    --mutex;
    if (empty != 0) {
        buffer[in] = item;
        in = (in + 1) % 10;
        ++full;
        --empty;
        printf("Producer produces item: %d\n", item);
    } else {
        printf("Buffer is full!\n");
    }

    ++mutex;
}

void consumer() {
    --mutex;
    if (full != 0) {
        int item = buffer[out];
        out = (out + 1) % 10;
        --full;
        ++empty;
        printf("Consumer consumes item: %d\n", item);
    } else {
        printf("Buffer is empty!\n");
    }

    ++mutex;
}

int main() {
    int n;
    printf("Enter the buffer size: ");
    scanf("%d", &empty);

    while (1) {
        printf("\nThe options are:");
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter the choice: ");
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
                exit(0);
                break;

            default:
                printf("Invalid input!\n");
        }
    }

    return 0;  
} 
