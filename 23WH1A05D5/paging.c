#include <stdio.h>

int main() {
    int mem_size, page_size, num_pages, page_table[20], i, logical_addr, page_num, offset, physical_addr;

    printf("Enter the memory size: ");
    scanf("%d", &mem_size);

    printf("Enter the page size: ");
    scanf("%d", &page_size);

    num_pages = mem_size / page_size;

    printf("Number of pages: %d\n", num_pages);

    printf("Enter the frame number for each page:\n");
    for (i = 0; i < num_pages; i++) {
        printf("Page %d: ", i);
        scanf("%d", &page_table[i]);
    }

    printf("Enter the logical address: ");
    scanf("%d", &logical_addr);

    page_num = logical_addr / page_size;
    offset = logical_addr % page_size;

    physical_addr = page_table[page_num] * page_size + offset;

    printf("Physical Address: %d\n", physical_addr);

    return 0;
}

