#include <stdio.h>

struct Segment {
    int base;   // Base address of the segment
    int limit;  // Size of the segment
};

int main() {
    int num_segments, segment_number, offset;
    
    // Get number of segments
    printf("Enter number of segments: ");
    scanf("%d", &num_segments);

    struct Segment segment_table[num_segments];

    // Input segment details (Base & Limit)
    for (int i = 0; i < num_segments; i++) {
        printf("Enter base address of segment %d: ", i);
        scanf("%d", &segment_table[i].base);
        printf("Enter limit (size) of segment %d: ", i);
        scanf("%d", &segment_table[i].limit);
    }

    // Input logical address
    printf("\nEnter segment number: ");
    scanf("%d", &segment_number);
    printf("Enter offset: ");
    scanf("%d", &offset);

    // Validate segment number
    if (segment_number >= num_segments) {
        printf("Error: Invalid segment number!\n");
        return 1;
    }

    // Validate offset
    if (offset >= segment_table[segment_number].limit) {
        printf("Error: Offset exceeds segment limit!\n");
        return 1;
    }

    // Calculate physical address
    int physical_address = segment_table[segment_number].base + offset;

    // Output result
    printf("\n--- Segmentation Simulation ---\n");
    printf("Segment Number: %d\n", segment_number);
    printf("Offset: %d\n", offset);
    printf("Base Address: %d\n", segment_table[segment_number].base);
    printf("Physical Address: %d\n", physical_address);

    return 0;
}
