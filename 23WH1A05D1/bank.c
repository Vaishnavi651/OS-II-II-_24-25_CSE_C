#include <stdio.h>
#include <stdlib.h>

void main() {
    int pro, res;
    int allocate[10][5], max[10][5], need[10][5], avail[5], safe[10];
    int finished[10] = {0};  // Track finished processes
    int k = 0;  // Safe sequence index

    // Input number of resources
    printf("Enter the number of resources: ");
    scanf("%d", &res);

    int instance[5];
    printf("Enter the maximum instances for each resource:\n");
    for (int i = 0; i < res; i++) {
        printf("%c = ", (i + 97)); // Display a, b, c, ...
        scanf("%d", &instance[i]);
        avail[i] = instance[i]; // Initialize available resources
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &pro);

    // Input Allocation Matrix
    printf("\nEnter the Allocation Matrix:\n");
    for (int i = 0; i < pro; i++) {
        printf("P[%d]: ", i);
        for (int j = 0; j < res; j++) {
            scanf("%d", &allocate[i][j]);
            avail[j] -= allocate[i][j]; // Reduce allocated from available
        }
    }

    // Input Max Matrix
    printf("\nEnter the Max Matrix:\n");
    for (int i = 0; i < pro; i++) {
        printf("P[%d]: ", i);
        for (int j = 0; j < res; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocate[i][j]; // Calculate Need Matrix
        }
    }

    // Safety Algorithm
    while (k < pro) {
        int found = 0;//found is used to track at least one resource is allocated

        for (int i = 0; i < pro; i++) {
            if (!finished[i]) {  // If process is not finished
                int canAllocate = 1;

                for (int j = 0; j < res; j++) {
                    if (need[i][j] > avail[j]) {  // If need exceeds available resources
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {  // If process can be allocated
                    safe[k++] = i;//adding process to safe sequence
                    for (int j = 0; j < res; j++) {
                        avail[j] += allocate[i][j]; // Release allocated resources
                    }
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {  // If no process was allocated in this round
            printf("\nSystem is NOT in a safe state. Deadlock possible.\n");
            exit(0);
        }
    }

    // Printing the Safe Sequence
    printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
    for (int i = 0; i < pro; i++) {
        printf("P[%d] ", safe[i]);
    }
    printf("\n");
}






