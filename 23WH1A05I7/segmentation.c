#include <stdio.h>

#define MAX_SEGMENTS 10

// Structure to represent a segment
struct Segment {
    int base;
    int limit;
};

int main() {
    struct Segment segments[MAX_SEGMENTS];
    int n;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    // Input base and limit for each segment
    for (int i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d %d", &segments[i].base, &segments[i].limit);
    }

    int choice;
    do {
        int segNum, offset;
        printf("\nEnter segment number and offset: ");
        scanf("%d %d", &segNum, &offset);

        // Check for valid segment number
        if (segNum < 0 || segNum >= n) {
            printf("Invalid segment number!\n");
        } else {
            // Check if offset is within the segment limit
            if (offset < segments[segNum].limit) {
                int physicalAddress = segments[segNum].base + offset;
                printf("Physical Address: %d\n", physicalAddress);
            } else {
                printf("Segmentation Fault: Offset exceeds segment limit!\n");
            }
        }

        printf("\nDo you want to try another address? (1: Yes, 0: No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    return 0;
}
