#include <stdio.h>
#include <stdlib.h>

int full = 0;
int empty = 10;
int mutex = 1;
int x = 0;

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
    printf("\nProducer produces item %d", x);
    signal(&full);
    signal(&mutex);
}

void consumer() {
    wait(&full);
    wait(&mutex);
    printf("\nConsumer consumes item %d", x);
    x--;
    signal(&empty);
    signal(&mutex);
}

int main() {
    int n, i;
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
        }
    }
}

