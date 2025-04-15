#include <stdio.h>

void LRU(int pages[], int n, int capacity) {
    int frames[capacity];     // Holds current pages in memory
    int recent[capacity];     // Stores last used time (index in pages[])
    int count = 0;
    int page_faults = 0, hits = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in memory
        for (int j = 0; j < count; j++) {
            if (frames[j] == page) {
                found = 1;
                recent[j] = i; // Update its last used time
                hits++;
                break;
            }
        }

        if (!found) {
            int replace_index = 0;

            // If there is space, just insert
            if (count < capacity) {
                replace_index = count;
                count++;
            } else {
                // Find the least recently used page
                int min_time = recent[0];
                for (int j = 1; j < capacity; j++) {
                    if (recent[j] < min_time) {
                        min_time = recent[j];
                        replace_index = j;
                    }
                }
            }

            // Replace or add the page
            frames[replace_index] = page;
            recent[replace_index] = i;
            page_faults++;
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits      : %d\n", hits);
    printf("Total Misses    : %d\n", page_faults); // Misses = Faults
}

int main() {
    int pages[] = {2, 3, 1, 3, 5, 1, 2, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    LRU(pages, n, capacity);

    return 0;
}
