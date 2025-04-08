#include <stdio.h>

void LRU(int pages[], int n, int capacity) {
    int frames[capacity], index[capacity], count = 0, page_faults = 0, hits = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                index[j] = i;
                hits++;
                break;
            }
        }

        if (!found) {
            int replace = 0;
            if (count < capacity)
                replace = count++;
            else {
                int min = index[0], min_index = 0;
                for (int j = 1; j < capacity; j++)
                    if (index[j] < min) {
                        min = index[j];
                        min_index = j;
                    }
                replace = min_index;
            }
            frames[replace] = pages[i];
            index[replace] = i;
            page_faults++;
        }
    }
    int misses = page_faults;
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hits);
    printf("Total Misses: %d\n", misses);
}

int main() {
    int pages[] = {2, 3, 1, 3, 5, 1, 2, 4};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;
    
    LRU(pages, n, capacity);
    return 0;
}
