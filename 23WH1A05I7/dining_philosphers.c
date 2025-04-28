#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5  // Number of philosophers

// Possible states
enum { THINKING, HUNGRY, EATING };
int state[N];

// Check if philosopher i can eat
void test(int i) {
    int left = (i + N - 1) % N;
    int right = (i + 1) % N;

    if (state[i] == HUNGRY && state[left] != EATING && state[right] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d is eating.\n", i);
    }
}

// Philosopher tries to pick up forks
void pickup(int i) {
    state[i] = HUNGRY;
    printf("Philosopher %d is hungry.\n", i);
    test(i);
}

// Philosopher puts down forks
void putdown(int i) {
    state[i] = THINKING;
    printf("Philosopher %d is thinking.\n", i);

    // After putting down, check if neighbors can eat
    test((i + N - 1) % N);
    test((i + 1) % N);
}

int main() {
    for (int i = 0; i < N; i++) {
        state[i] = THINKING;
    }

    // Simulate philosophers one by one
    for (int i = 0; i < N; i++) {
        printf("Philosopher %d is thinking.\n", i);
        sleep(1);

        pickup(i);
        if (state[i] == EATING) {
            sleep(1);
            putdown(i);
            printf("Philosopher %d finished eating.\n", i);
        } else {
            printf("Philosopher %d could not eat (neighbors eating).\n", i);
        }
    }

    printf("Simulation complete: All philosophers attempted to eat.\n");
    return 0;
}
