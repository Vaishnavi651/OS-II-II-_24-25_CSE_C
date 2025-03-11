#include <stdio.h>

void main() {
    int process, no_of_resources;
    int allocated[10][5], MAX[10][5], need[10][5], available[5], safeSeq[10], k = 0;

    printf("\nEnter the number of resources: ");
    scanf("%d", &no_of_resources);

    int instance[5];
    printf("\nEnter the max instances of each resource\n");
    for (int i = 0; i < no_of_resources; i++) {
        printf("%c= ", (i + 97));
        scanf("%d", &instance[i]);
        available[i] = instance[i];
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &process);

    // Input allocation matrix
    printf("\nEnter the allocation matrix:\n");
    for (int i = 0; i < process; i++) {
        printf("P[%d]  ", i);
        for (int j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
            available[j] -= allocated[i][j];  // Subtract allocated from available
        }
    }

    // Input MAX matrix
    printf("\nEnter the MAX matrix:\n");
    for (int i = 0; i < process; i++) {
        printf("P[%d]  ", i);
        for (int j = 0; j < no_of_resources; j++) {
            scanf("%d", &MAX[i][j]);
            need[i][j] = MAX[i][j] - allocated[i][j];  // Need = MAX - Allocated
        }
    }

    // Safety algorithm
    int finish[10] = {0};
    while (k < process) {
        int found = 0;
        for (int i = 0; i < process; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (int j = 0; j < no_of_resources; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    safeSeq[k++] = i;
                    for (int j = 0; j < no_of_resources; j++) {
                        available[j] += allocated[i][j];  // Release allocated resources
                    }
                    finish[i] = 1;
                    found = 1;
                    break;
                }
            }
        }
        if (!found) {
            printf("\nSystem is not in a safe state.\n");
            return;
        }
    }

    // Print safe sequence
    printf("\nSystem is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < process; i++) {
        printf("P[%d] ", safeSeq[i]);
    }
    printf("\n");
}
