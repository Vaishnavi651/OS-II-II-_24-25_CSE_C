#include <stdio.h>
#include <stdlib.h>

int main() {
    int numSegments, segmentNumber, offset, physicalAddress;
    printf("Enter the number of segments: ");
    scanf("%d", &numSegments);

    int base[numSegments], limit[numSegments];
    printf("Enter base address and limit for each segment:\n");
    for (int i = 0; i < numSegments; i++) {
        printf("Segment %d -> Base Address: ", i);
        scanf("%d", &base[i]);
        printf("Segment %d -> Limit (Size): ", i);
        scanf("%d", &limit[i]);
    }
    printf("Enter segment number: ");
    scanf("%d", &segmentNumber);
    printf("Enter offset: ");
    scanf("%d", &offset);

    if (segmentNumber >= numSegments) {
        printf("Error: Invalid segment number!\n");
    }
    else if (offset >= limit[segmentNumber]) {
        printf("Segmentation Fault: Offset exceeds segment limit!\n");
    }
    else {
        physicalAddress = base[segmentNumber] + offset;
        printf("Logical Address (Segment %d, Offset %d) -> Physical Address %d\n",
               segmentNumber, offset, physicalAddress);
    }

    return 0;
}
