// Paging simulation in C
 # include <stdio.h>

 # define PAGE_SIZE 4 // Each page has 4 - byte size
 # define TOTAL_PAGES 4 // Assume we have 4 pages

 int main () {
 // Page table mapping logical pages to physical frames
 int pageTable [ TOTAL_PAGES ] = {3 , 1 , 2 , 0};

 int logicalAddress , pageNumber , offset , physicalAddress ;

 // Taking logical address input
 printf (" Enter logical address ( Page Number * PAGE_SIZE +Offset ): ") ;

 scanf ("%d", & logicalAddress ) ;
 // Calculate page number and offset
 pageNumber = logicalAddress / PAGE_SIZE ;
 offset = logicalAddress % PAGE_SIZE ;

 // Check if the page number is valid
 if ( pageNumber >= TOTAL_PAGES ) {
 printf (" Error : Invalid Page Number !\n") ;
 return 1;
 }

 // Get frame number from the page table
 int frameNumber = pageTable [ pageNumber ];

 // Calculate physical address
 physicalAddress = ( frameNumber * PAGE_SIZE ) + offset ;

 // Output results
 printf (" Logical Address : %d\n", logicalAddress ) ;
 printf (" Page Number : %d, Offset : %d\n", pageNumber , offset ) ;
 printf (" Frame Number : %d\n", frameNumber ) ;
 printf (" Physical Address : %d\n", physicalAddress ) ;

 return 0;
 }
