#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPages, pageSize, logicalAddress, pageNumber, offset, physicalAddress;
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    
    printf("Enter the page size (in bytes): ");
    scanf("%d", &pageSize);

    int *pageTable = (int *)malloc(numPages * sizeof(int));  
    printf("Enter the frame number for each page:\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &pageTable[i]);
    }
    printf("Enter a logical address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;
    if (pageNumber >= numPages) {
        printf("Error: Invalid page number! Logical address out of bounds.\n");
    } else {
        physicalAddress = (pageTable[pageNumber] * pageSize) + offset;
        printf("Logical Address %d -> Physical Address %d\n", logicalAddress, physicalAddress);
    }

    free(pageTable); 
    return 0;
}
