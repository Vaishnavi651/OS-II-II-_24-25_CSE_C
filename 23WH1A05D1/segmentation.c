#include <stdio.h>

int main() {
    int segmentTable[10][2]; 
    int n;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    printf("Enter base and limit for each segment:\n");
    for (int i = 0; i < n; i++) {
        printf("Segment %d base: ", i);
        scanf("%d", &segmentTable[i][0]);
        printf("Segment %d limit: ", i);
        scanf("%d", &segmentTable[i][1]);
    }

    int segmentNumber, offset;

    printf("Enter segment number: ");
    scanf("%d", &segmentNumber);
    printf("Enter offset: ");
    scanf("%d", &offset);

    if (segmentNumber >= n) {
        printf("Error: Invalid segment number!\n");
        return 1;
    }

    if (offset >= segmentTable[segmentNumber][1]) {
        printf("Error: Offset exceeds segment limit!\n");
        return 1;
    }

    int physicalAddress = segmentTable[segmentNumber][0] + offset;

    printf("Physical address: %d\n", physicalAddress);

    return 0;
}

