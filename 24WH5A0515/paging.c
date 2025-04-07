#include< stdio.h >
#define PAGE_SIZE 4 
# define TOTAL_PAGES 4 
int main () {
  int pageTable [ TOTAL_PAGES ] = {3 , 1 , 2 , 0};
  int logicalAddress , pageNumber , offset , physicalAddress ;
  printf (" Enter logical address ( Page Number * PAGE_SIZE +Offset ): ") ;
  scanf ("%d", & logicalAddress ) ;
  pageNumber = logicalAddress / PAGE_SIZE ;
  offset = logicalAddress % PAGE_SIZE ;
  if ( pageNumber >= TOTAL_PAGES ) {
     printf (" Error : Invalid Page Number !\n") ;
     return 1;
   }
   int frameNumber = pageTable [ pageNumber ];
   physicalAddress = ( frameNumber * PAGE_SIZE ) + offset ;
   printf (" Logical Address : %d\n", logicalAddress ) ;
   printf (" Page Number : %d, Offset : %d\n", pageNumber , offset ) ;
   printf (" Frame Number : %d\n", frameNumber ) ;
   printf (" Physical Address : %d\n", physicalAddress ) ;
   return 0;
}
