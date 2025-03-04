#include <stdio.h>
#include <stdbool.h>

#define MAX 10 // Maximum number of processes
#define RESOURCE_TYPES 3types

int processes, resources;
int allocation[MAX][RESOURCE_TYPES], maximum[MAX][RESOURCE_TYPES], need[MAX][RESOURCE_TYPES];
int available[RESOURCE_TYPES], safeSequence[MAX];

// Function to check if a process can be allocated resources
bool isSafe() {
    int work[RESOURCE_TYPES];
    bool finish[MAX] = {0};
    int count = 0;

    // Initialize work[] with the available resources
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    while (count < processes) {
        bool found = false;

        for (int i = 0; i < processes; i++) {
            // Check if process i is not finished and its needs can be met with current work[]
            if (!finish[i]) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                // If all needs can be met, add its allocated resources to work[]
                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i; // Add process to safe sequence
                    finish[i] = true;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            return false; // No process could be executed, system is in an unsafe state
        }
    }
    return true;
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resource types: ");
    scanf("%d", &resources);

    printf("\nEnter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter the maximum demand matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    // Calculate the need matrix
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    // Check if the system is in a safe state
    if (isSafe()) {
        printf("\nThe system is in a safe state.\n");
        printf("Safe Sequence is: ");
        for (int i = 0; i < processes; i++) {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nThe system is in an unsafe state.\n");
    }

    return 0;
}

