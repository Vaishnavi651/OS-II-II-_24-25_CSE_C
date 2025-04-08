#include <stdio.h>

int predict(int pages[], int n, int frame[], int frameSize, int index) {
    int farthest = index, replaceIndex = -1;
    for (int i = 0; i < frameSize; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == n) 
            return i;
    }
    return (replaceIndex == -1) ? 0 : replaceIndex;
}

void optimalPageReplacement(int pages[], int n, int frameSize) {
    int frame[frameSize], count = 0, page_faults = 0, hits = 0, misses = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++)
            if (frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }

        if (!found) {
            if (count < frameSize)
                frame[count++] = pages[i];
            else {
                int replaceIndex = predict(pages, n, frame, frameSize, i + 1);
                frame[replaceIndex] = pages[i];
            }
            page_faults++;
            misses++;
        }
    }
    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hits);
    printf("Total Misses: %d\n", misses);
}

int main() {
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frameSize = 3;
    
    optimalPageReplacement(pages, n, frameSize);
    return 0;
}
