#include <stdio.h>

int predict(int pages[], int n, int index, int frame[], int capacity) {
    int res = -1, farthest = index;

    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (res == -1) ? 0 : res;
}

int main() {
    int n, pages[50], frames[10], capacity, faults = 0, count = 0;

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
            if (count < capacity) {
                frames[count++] = pages[i];
            } else {
                int idx = predict(pages, n, i + 1, frames, capacity);
                frames[idx] = pages[i];
            }
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}

