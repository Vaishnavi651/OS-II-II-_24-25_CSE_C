#include <stdio.h>
#include <stdbool.h>

int findOptimal(int pages[], int memory[], int n, int currentIndex, int capacity) {
    int farthest = currentIndex;
    int replaceIndex = -1;

    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = currentIndex + 1; j < n; j++) {
            if (memory[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == n) // not found again
            return i;
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

void Optimal(int pages[], int n, int capacity) {
    int memory[capacity];
    int count = 0, page_faults = 0, hits = 0;
    bool in_memory[100] = {false};

    for (int i = 0; i < n; i++) {
        printf("Page %d: ", pages[i]);
        if (in_memory[pages[i]]) {
            hits++;
            printf("HIT\n");
        } else {
            if (count < capacity) {
                memory[count++] = pages[i];
            } else {
                int idx = findOptimal(pages, memory, n, i, capacity);
                printf("REPLACE %d with %d\n", memory[idx], pages[i]);
                in_memory[memory[idx]] = false;
                memory[idx] = pages[i];
            }
            in_memory[pages[i]] = true;
            page_faults++;

            // print current memory state
            printf("Memory: ");
            for (int k = 0; k < count; k++)
                printf("%d ", memory[k]);
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hits);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    Optimal(pages, n, capacity);
    return 0;
}


