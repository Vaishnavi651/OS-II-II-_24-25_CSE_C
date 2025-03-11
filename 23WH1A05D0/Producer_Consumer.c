#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100
int buffer[MAX_BUFFER_SIZE] = {1, 2, 3, 4, 5};
int BUFFER_SIZE;
int in = 0, out = 0;
int full = 0;
int empty;
int mutex = 1;
int x = 0;

void displayBuffer() {
    printf("\nBuffer: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (i >= out && i < in) {
            printf("%d ", buffer[i % BUFFER_SIZE]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

void wait(int *S) {
    while (*S <= 0);
    (*S)--;
}

void signal(int *S) {
    (*S)++;
}

void producer() {
    wait(&empty);
    wait(&mutex);

    x++;
    buffer[in] = x;
    in = (in + 1) % BUFFER_SIZE;

    printf("\nProducer produces item %d", x);
    displayBuffer();

    signal(&full);
    signal(&mutex);
}

void consumer() {
    wait(&full);
    wait(&mutex);

    int item = buffer[out];
    printf("\nConsumer consumes item %d", item);
    buffer[out] = 0;  // Clear consumed item (optional for visualization)
    out = (out + 1) % BUFFER_SIZE;

    displayBuffer();

    signal(&empty);
    signal(&mutex);
}

int main() {
    int n, i;
    printf("\nEnter buffer size (max %d): ", MAX_BUFFER_SIZE);
    scanf("%d", &BUFFER_SIZE);

    if (BUFFER_SIZE > MAX_BUFFER_SIZE || BUFFER_SIZE <= 0) {
        printf("\nInvalid buffer size! Exiting...\n");
        return 1;
    }

    empty = BUFFER_SIZE;

    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    for (i = 1; i > 0; i++) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            if (mutex == 1 && empty != 0) {
                producer();
            } else {
                printf("\nBuffer is full!");
            }
            break;
        case 2:
            if (mutex == 1 && full != 0) {
                consumer();
            } else {
                printf("\nBuffer is empty!");
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid choice!");
        }
    }
}

	

