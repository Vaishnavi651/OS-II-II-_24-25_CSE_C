#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_pages, page_size, logical_address;
    
    // Get user input
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    printf("Enter the page size (in bytes): ");
    scanf("%d", &page_size);

    // Generate a simple page table (each page is mapped to itself for simplicity)
    int page_table[num_pages];
    for (int i = 0; i < num_pages; i++) {
        page_table[i] = i; // Direct mapping (page i → frame i)
    }

    // Input logical address
    printf("Enter a logical address: ");
    scanf("%d", &logical_address);

    // Calculate page number and offset
    int page_number = logical_address / page_size;
    int offset = logical_address % page_size;

    // Check if the page number is valid
    if (page_number >= num_pages) {
        printf("Error: Invalid logical address! Page number out of bounds.\n");
        return 1;
    }

    // Perform logical-to-physical mapping
    int frame_number = page_table[page_number];
    int physical_address = (frame_number * page_size) + offset;

    // Output results
    printf("\n--- Paging Simulation ---\n");
    printf("Logical Address: %d\n", logical_address);
    printf("Page Number: %d\n", page_number);
    printf("Offset: %d\n", offset);
    printf("Mapped to Frame: %d\n", frame_number);
    printf("Physical Address: %d\n", physical_address);

    return 0;
}

