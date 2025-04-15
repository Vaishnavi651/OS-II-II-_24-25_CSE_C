#include <stdio.h>
#include <stdlib.h>  // For system("clear")

int main() {
    int n, i, sno, offset, pa;
    int base[10], limit[10];

    // Clear screen
    system("clear");

    printf("Enter the number of segments: ");
    scanf("%d", &n);

    // Input base and limit for each segment
    for(i = 0; i < n; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d %d", &base[i], &limit[i]);
    }

    // Get logical address input
    printf("\nEnter Segment Number and Offset: ");
    scanf("%d %d", &sno, &offset);

    // Validation
    if (sno < 0 || sno >= n) {
        printf("\nInvalid Segment Number!");
    } else if (offset < 0 || offset >= limit[sno]) {
        printf("\nOffset exceeds the segment limit!");
    } else {
        pa = base[sno] + offset;
        printf("\nThe Physical Address is: %d", pa);
    }

    getchar(); // Wait for user input
    return 0;
}

