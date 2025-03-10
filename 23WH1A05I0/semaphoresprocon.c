#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int mutex = 1;
int full = 0;
int empty = 10, x = 0;
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
    signal(&mutex);
    signal(&full);
}
void consumer() {
    do {
        wait(&full);
        wait(&mutex);

        printf("\nConsumer consumes item %d", x);
        x--;
        signal(&mutex);
        signal(&empty);
        sleep(1);
    } while (x > 0);
}
int main() {
    for (int i = 0; i < 10; i++) {
        producer();
        sleep(1);
        consumer();
    }
    return 0;
}
