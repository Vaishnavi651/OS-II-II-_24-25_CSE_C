#include <stdio.h>

int main() {
    int memSize, pageSize, numPages, i;
    int frameTable[100]; // stores frame number for each page

    // Input memory size and page size
    printf("Enter total memory size (in bytes): ");
    scanf("%d", &memSize);

    printf("Enter page size (in bytes): ");
    scanf("%d", &pageSize);

    // Calculate number of pages
    numPages = memSize / pageSize;
    printf("\nTotal number of pages: %d\n", numPages);

    // Input the frame number for each page
    printf("\nEnter frame number for each page (0 to %d):\n", numPages - 1);
    for(i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &frameTable[i]);
    }

    // Simulate logical to physical address translation
    int logAddr, pageNum, offset, physAddr;
    printf("\nEnter a logical address (0 to %d): ", memSize - 1);
    scanf("%d", &logAddr);

    pageNum = logAddr / pageSize;
    offset = logAddr % pageSize;
    physAddr = frameTable[pageNum] * pageSize + offset;

    printf("\nLogical Address: %d\n", logAddr);
    printf("Page Number: %d\n", pageNum);
    printf("Offset: %d\n", offset);
    printf("Physical Address: %d\n", physAddr);

    return 0;
}
