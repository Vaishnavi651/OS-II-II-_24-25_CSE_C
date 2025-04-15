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
  int best_index =-1;
  for (int j = 0; j < num_blocks; j++) {
  if (block_size[j] >= process_size[i]) {
  if (best_index ==-1 || block_size[j] <
 block_size[best_index]) {
  best_index = j;
  }
  }
  }
  if (best_index !=-1) {
  allocation[i] = best_index;
  block_size[best_index]-= process_size[i];
  }
  }
  printf("\nProcess No.\tProcess Size\tBlock No.\n");
  for (int i = 0; i < num_processes; i++) {
  if (allocation[i] !=-1) {
  printf("%d\t\t%d\t\t%d\n", i + 1, process_size[i],
 allocation[i] + 1);
  } else {
  printf("%d\t\t%d\t\tNot Allocated\n", i + 1,
 process_size[i]);
  }
  }
  return 0;
  }


/* Enter the size ofmemory: 1000
 Enter the number ofmemory blocks: 5
 Enter the size ofmemory block1: 200
 Enter the size ofmemory block2: 300
 Enter the size ofmemory block3: 100
 Enter the size ofmemory block4: 150
 Enter the size ofmemory block5: 250
 Enter the number ofprocesses:4
 Enter the size ofprocess 1:120
 Enter the size ofprocess 2:200
 Enter the size ofprocess 3:350*/
