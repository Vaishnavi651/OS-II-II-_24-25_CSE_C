#include <stdio.h>

int main() {
    int i, j, k, process, no_of_resources;
    int allocated[10][10], max[10][10], need[10][10], availability[10];
    int finished[10], safe_sequence[10], count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &process);
    printf("Enter the number of resources: ");
    scanf("%d", &no_of_resources);

    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("\nEnter the Maximum Matrix:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < no_of_resources; i++) {
        scanf("%d", &availability[i]);
    }

    printf("\nNeed Matrix:\n");
    for (i = 0; i < process; i++) {
        for (j = 0; j < no_of_resources; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < process; i++) {
        finished[i] = 0;
    }

    printf("\nStep-by-step resource allocation and availability:\n");
    while (count < process) {
        int found = 0;
        for (i = 0; i < process; i++) {
            if (finished[i] == 0) { 
                int can_allocate = 1;
                for (j = 0; j < no_of_resources; j++) {
                    if (need[i][j] > availability[j]) {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate) {
                    printf("Process P%d is allocated\n", i);
                    printf("Available resources before allocation: ");
                    for (j = 0; j < no_of_resources; j++) {
                        printf("%d ", availability[j]);
                    }
                    printf("\n");
                    
                    for (j = 0; j < no_of_resources; j++) {
                        availability[j] += allocated[i][j];
                    }

                    printf("Available resources after allocation: ");
                    for (j = 0; j < no_of_resources; j++) {
                        printf("%d ", availability[j]);
                    }
                    printf("\n");

                    safe_sequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nThe system is in an unsafe state (Deadlock possible).\n");
            return 1;
        }
    }

    printf("\nThe system is in a safe state.\nSafe Sequence: < ");
    for (i = 0; i < process; i++) {
        printf("P%d-> ", safe_sequence[i]);
    }
    printf(">\n");

    return 0;
}
