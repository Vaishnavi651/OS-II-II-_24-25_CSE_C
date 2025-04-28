#include <stdio.h>
#include <stdbool.h>

void LRU(int pages[], int n, int capacity) {
    int memory[capacity], recent[100]; // recent[i] stores last used time of page i
    int count = 0, page_faults = 0, hits = 0;

    for (int i = 0; i < 100; i++) {
        recent[i] = -1; // Initialize all recent usages as -1
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if page is already in memory (hit)
        for (int j = 0; j < count; j++) {
            if (memory[j] == pages[i]) {
                hits++;
                found = true;
                break;
            }
        }

        // If page not found (page fault)
        if (!found) {
            if (count < capacity) {
                memory[count++] = pages[i];
            } else {
                // Find least recently used page
                int lru_index = 0;
                for (int j = 1; j < capacity; j++) {
                    if (recent[memory[j]] < recent[memory[lru_index]]) {
                        lru_index = j;
                    }
                }
                memory[lru_index] = pages[i];
            }
            page_faults++;
        }

        // Update recent usage
        recent[pages[i]] = i;
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hits);
    printf("Total Misses: %d\n", page_faults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3, 5, 1, 0};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    LRU(pages, n, capacity);
    return 0;
}


