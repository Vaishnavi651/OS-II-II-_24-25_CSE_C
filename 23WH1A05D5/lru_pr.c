#include <stdio.h>

int search(int key, int frame[], int capacity) {
    for (int i = 0; i < capacity; i++)
        if (frame[i] == key) return i;
    return -1;
}

int main() {
    int n, pages[50], frames[10], counter[10], capacity;
    int faults = 0, time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int pos = search(pages[i], frames, capacity);

        if (pos == -1) {
            int lru = 0;
            for (int j = 1; j < capacity; j++)
                if (counter[j] < counter[lru]) lru = j;

            frames[lru] = pages[i];
            counter[lru] = ++time;
            faults++;
        } else {
            counter[pos] = ++time;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}

