#include <stdio.h>
#include <stdbool.h>

void FCFS(int pages[], int n, int capacity) {
    int queue[capacity];
    int front = 0, count = 0;
    int page_faults = 0, hits = 0;
    bool in_memory[100] = { false }; // Assumes page numbers are < 100

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        if (in_memory[page]) {
            // Page hit
            hits++;
        } else {
            // Page fault
            if (count < capacity) {
                queue[count++] = page;
            } else {
                // Remove the oldest page
                in_memory[queue[front]] = false;
                queue[front] = page;
                front = (front + 1) % capacity;
            }
            in_memory[page] = true;
            page_faults++;
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits      : %d\n", hits);
    printf("Total Misses    : %d\n", page_faults); // Misses = faults
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 5, 1, 0};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    FCFS(pages, n, capacity);

    return 0;
}
