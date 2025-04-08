// Segmentation Simulation in C
# include<stdio.h>

 # define TOTAL_SEGMENTS 3 // Number of segments

 // Structure to store segment table entries
 struct Segment {
int base ; // Base address of the segment
int limit ; // Size ( length ) of the segment
 };
 int main () {
 struct Segment segmentTable [ TOTAL_SEGMENTS ] = {
 {100 , 500} , // Segment 0 ( Code )
 {700 , 300} , // Segment 1 ( Data )
 {1200 , 200} // Segment 2 ( Stack )
 };

 int segmentNumber , offset , physicalAddress ;

 // Taking logical address input
 printf (" Enter Segment Number and Offset : ") ;
 scanf ("%d %d", & segmentNumber , & offset ) ;
 // Check if the segment number is valid
 if ( segmentNumber >= TOTAL_SEGMENTS || segmentNumber < 0) {
 printf (" Error : Invalid Segment Number !\n") ;
 return 1;
 }
 // Check if the offset is within segment limit
 if ( offset >= segmentTable [ segmentNumber ]. limit ) {
 printf (" Error : Segmentation Fault ! Offset out of bounds .\n") ;
 return 1;
 }
 // Calculate the Physical Address
 physicalAddress = segmentTable [ segmentNumber ]. base + offset ;

 // Display Results
 printf (" Segment Number : %d, Offset : %d\n", segmentNumber ,offset ) ;

 printf (" Base Address : %d, Limit : %d\n", segmentTable [segmentNumber ]. base , segmentTable [ segmentNumber ]. limit ) ;

 printf (" Physical Address : %d\n", physicalAddress ) ;

 return 0;
 }
