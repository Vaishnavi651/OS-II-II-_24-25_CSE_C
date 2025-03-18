#include<stdio.h>

int main() {
  int p, c, count = 0, i, j, alc[10][10], max[10][10], need[10][10], safe[10], instances[10], available[10], done[10], terminate = 0;
  printf("Enter the number of process and resources: ");
  scanf("%d %d", &p, &c);
  // p is number of process and c is number of resources 
  printf("Enter allocation of resource of all process %dx%d matrix: ", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", &alc[i][j]);
    }
  }
  printf("Enter the max resource process required %dx%d matrix: ", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", &max[i][j]);
    }
  }
  printf("Enter the number of instances for each resource: ");
  for (i = 0; i < c; i++)
    scanf("%d", &instances[i]);

  // Calculate available resources based on instances and allocation
  for (i = 0; i < c; i++) {
    available[i] = instances[i];
    for (j = 0; j < p; j++) {
      available[i] -= alc[j][i];
    }
  }

  printf("\nNeed resources matrix:\n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }
  // once process is executed; variable 'done' will stop them from executing again 
  for (i = 0; i < p; i++) {
    done[i] = 0;
  }
  while (count < p) {
    for (i = 0; i < p; i++) {
      if (done[i] == 0) {
        for (j = 0; j < c; j++) {
          if (need[i][j] > available[j])
            break;
        }
        //when need matrix is not greater than available matrix then if j==c will true
        if (j == c) {
          safe[count] = i;
          done[i] = 1;
          /* now process gets executed, release the resources, and add them in available resources */
          for (j = 0; j < c; j++) {
            available[j] += alc[i][j];
          }
          count++;
          terminate = 0;
        } else {
          terminate++;
        }
      }
    }
    if (terminate == (p - 1)) {
      printf("Safe sequence does not exist");
      break;
    }

  }
  if (terminate != (p - 1)) {
    printf("\nAvailable resource after completion:\n");
    for (i = 0; i < c; i++) {
      printf("%d\t", available[i]);
    }
    printf("\nSafe sequence is:\n");
    for (i = 0; i < p; i++) {
      printf("P%d\t", safe[i]);
    }
  }

  return 0;
}
