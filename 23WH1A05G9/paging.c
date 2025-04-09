#include <stdio.h>

#define MAX_PAGES 100  // define a max size to avoid dynamic memory

int main() {
    int FRAME_SIZE, NUM_PAGES, NUM_FRAMES;
    int pageTable[MAX_PAGES];

    printf("Enter Frame Size: ");
    scanf("%d", &FRAME_SIZE);
    printf("Enter Number of Pages (<= %d): ", MAX_PAGES);
    scanf("%d", &NUM_PAGES);
    printf("Enter Number of Frames: ");
    scanf("%d", &NUM_FRAMES);

    if (NUM_PAGES > MAX_PAGES) {
        printf("Too many pages! Max allowed is %d.\n", MAX_PAGES);
        return 1;
    }

    printf("Enter the frame number for each page:\n");
    for (int i = 0; i < NUM_PAGES; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }

    int pageNumber, offset;
    printf("\nEnter Logical Address (Page Number and Offset): ");
    scanf("%d %d", &pageNumber, &offset);

    if (pageNumber >= NUM_PAGES || offset >= FRAME_SIZE) {
        printf("Invalid logical address!\n");
    } else {
        int physicalAddress = pageTable[pageNumber] * FRAME_SIZE + offset;
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
}
