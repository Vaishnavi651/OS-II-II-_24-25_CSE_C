 #include <stdio.h>
  int main() {
 int memory_size, num_blocks, num_processes;
 int block_size[10], process_size[10], allocation[10];
 printf("Enter the size of memory: ");
 scanf("%d", &memory_size);
 printf("Enter the number of memory blocks: ");
 scanf("%d", &num_blocks);
 for (int i = 0; i < num_blocks; i++) {
 printf("Enter the size of memory block %d: ", i + 1);
 
  scanf("%d", &block_size[i]);
  }
  printf("Enter the number of processes: ");
  scanf("%d", &num_processes);
  for (int i = 0; i < num_processes; i++) {
  printf("Enter the size of process %d: ", i + 1);
  scanf("%d", &process_size[i]);
  allocation[i] =-1;
  }
  for (int i = 0; i < num_processes; i++) {
  int worst_index =-1;
  for (int j = 0; j < num_blocks; j++) {
  if (block_size[j] >= process_size[i]) {
  if (worst_index ==-1 || block_size[j] >
 block_size[worst_index]) {
  worst_index = j;
  }
  }
  }
  if (worst_index !=-1) {
  allocation[i] = worst_index;
  block_size[worst_index]-= process_size[i];
  }
  }
  printf("\nProcess No.\tProcess Size\tBlock No.\n");
  for (int i = 0; i < num_processes; i++) {
  if (allocation[i] !=-1) {
  printf("%d\t\t%d\t\t%d\n", i + 1, process_size[i],
 allocation[i] + 1);
  } else {
  printf("%d\t\t%d\t\tNot Allocated\n", i + 1,Enter the size of memory: 1000
/*Enter the number of memory blocks: 5
Enter the size of memory block 1: 200
Enter the size of memory block 2: 300
Enter the size of memory block 3: 100
Enter the size of memory block 4: 150
Enter the size of memory block 5: 250
Enter the number of processes: 4
Enter the size of process 1: 120
Enter the size of process 2: 200
Enter the size of process 3: 350
Enter the size of process 4: 70

Process No.     Process Size    Block No.
1               120             2
2               200             5
3               350             Not Allocated
4               70              1*/
