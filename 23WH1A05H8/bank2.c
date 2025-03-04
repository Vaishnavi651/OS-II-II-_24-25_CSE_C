#include <stdio.h>
#include <stdlib.h>

void calculateNeed(int processes, int resources, int max[processes][resources], int allocation[processes][resources], int need[processes][resources]) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void processCompletion(int processes, int resources, int max[processes][resources], int allocation[processes][resources], int available[resources]) {
    int need[processes][resources];
    calculateNeed(processes, resources, max, allocation, need);

    int finish[processes]; // 0 for false, 1 for true
    for (int i = 0; i < processes; i++) {
        finish[i] = 0; // Initialize all processes as unfinished
    }

    int work[resources];
    for (int i = 0; i < resources; i++) {
        work[i] = available[i]; // Initialize work with available resources
    }

    int completedProcesses = 0;

    while (completedProcesses < processes) {
        int found = 0; // Flag to check if a process can be completed in this iteration

        for (int p = 0; p < processes; p++) {
            if (finish[p] == 0) { // If process p is not finished
                int canFinish = 1; // Assume it can finish

                // Check if the process can finish
                for (int j = 0; j < resources; j++) {
                    if (need[p][j] > work[j]) {
                        canFinish = 0; // Not enough resources
                        break;
                    }
                }

                // If the process can finish
                if (canFinish) {
                    // Simulate the allocation of resources
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[p][k]; // Update work
                    }
                    finish[p] = 1; // Mark process as finished
                    completedProcesses++; // Increment completed processes
                    found = 1; // A process was found that can finish

                    // Print the completion of the process
                    printf("Process P%d has completed.\n", p);
                }
            }
        }

        // If no process could be found that can finish, we are in a deadlock
        if (found == 0) {
            printf("Deadlock detected! No more processes can complete.\n");
            break;
        }
    }

    // Check if all processes finished
    if (completedProcesses == processes) {
        printf("All processes have completed successfully.\n");
    }
}

int main() {
    int processes, resources;

    // Get the number of processes and resources from the user
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    // Dynamically allocate matrices based on user input
    int allocation[processes][resources];
    int max[processes][resources];
    int available[resources];

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input max matrix
    printf("Enter the max matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    // Call the process completion function
    processCompletion(processes, resources, max, allocation, available);

    return 0;
}
