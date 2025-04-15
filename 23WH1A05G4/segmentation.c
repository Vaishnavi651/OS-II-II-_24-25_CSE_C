#include <stdio.h>

#define TOTAL_SEGMENTS 3

struct Segment {
    int base;
    int limit;
};

int main() {
    struct Segment segmentTable[TOTAL_SEGMENTS] = {
        {100, 500},
        {700, 300},
        {1200, 200}
    };

    int segmentNumber, offset, physicalAddress;

    printf("Enter Segment Number and Offset: ");
    scanf("%d %d", &segmentNumber, &offset);

    if (segmentNumber >= TOTAL_SEGMENTS || segmentNumber < 0) {
        printf("Error: Invalid Segment Number!\n");
        return 1;
    }

    if (offset >= segmentTable[segmentNumber].limit) {
        printf("Error: Segmentation Fault! Offset out of bounds.\n");
        return 1;
    }

    physicalAddress = segmentTable[segmentNumber].base + offset;

    printf("Segment Number: %d, Offset: %d\n", segmentNumber, offset);
    printf("Base Address: %d, Limit: %d\n",
           segmentTable[segmentNumber].base, segmentTable[segmentNumber].limit);
    printf("Physical Address: %d\n", physicalAddress);

    return 0;
}
