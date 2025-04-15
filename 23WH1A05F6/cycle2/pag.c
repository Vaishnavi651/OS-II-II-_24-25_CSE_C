#include <stdio.h>
#include <stdlib.h>  // For system("clear")

int main()
{
    int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
    int s, fno[20];

    // Clear screen (for Unix/Linux/macOS)
    system("clear");

    printf("\nEnter the memory size -- ");
    scanf("%d", &ms);

    printf("\nEnter the page size -- ");
    scanf("%d", &ps);

    nop = ms / ps;
    printf("\nThe no. of pages available in memory are -- %d", nop);

    printf("\nEnter number of pages required for the process -- ");
    scanf("%d", &s);

    if(s > nop) {
        printf("\nMemory is Full");
        return 0;
    }

    printf("\nEnter page table (frame numbers for each page) -- \n");
    for(i = 0; i < s; i++) {
        printf("Page %d --> Frame: ", i);
        scanf("%d", &fno[i]);
    }

    printf("\nEnter the page number and offset to find Physical Address -- ");
    scanf("%d %d", &y, &offset);

    if (y < 0 || y >= s || offset < 0 || offset >= ps) {
        printf("\nInvalid Page Number or Offset");
    } else {
        pa = fno[y] * ps + offset;
        printf("\nThe Physical Address is -- %d", pa);
    }

    getchar(); // To hold the screen
    return 0;
}

