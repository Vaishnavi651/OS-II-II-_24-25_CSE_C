#include <stdio.h>

#define MAX_SEGMENTS 100  // define max segments for static array

int main() {
    int NUM_SEGMENTS;
    int base[MAX_SEGMENTS], limit[MAX_SEGMENTS];

    printf("Enter number of segments (<= %d): ", MAX_SEGMENTS);
    scanf("%d", &NUM_SEGMENTS);

    if (NUM_SEGMENTS > MAX_SEGMENTS) {
        printf("Too many segments! Max allowed is %d.\n", MAX_SEGMENTS);
        return 1;
    }

    printf("Enter base and limit for each segment:\n");
    for (int i = 0; i < NUM_SEGMENTS; i++) {
        printf("Segment %d:\n", i);
        printf("  Base: ");
        scanf("%d", &base[i]);
        printf("  Limit: ");
        scanf("%d", &limit[i]);
    }

    int segmentNumber, offset;
    printf("\nEnter Logical Address (Segment Number and Offset): ");
    scanf("%d %d", &segmentNumber, &offset);

    if (segmentNumber >= NUM_SEGMENTS || offset >= limit[segmentNumber]) {
        printf("Invalid logical address!\n");
    } else {
        int physicalAddress = base[segmentNumber] + offset;
        printf("Physical Address = %d\n", physicalAddress);
    }

    return 0;
}
