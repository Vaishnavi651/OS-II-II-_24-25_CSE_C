#include <stdio.h>

int main() {
    int n, pages[50], frames[10], capacity, front = 0, count = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}

