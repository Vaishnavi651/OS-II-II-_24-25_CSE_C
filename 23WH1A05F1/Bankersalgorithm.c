#include <stdio.h>
#include <stdbool.h>

int numProcesses, numResources;
int total[10], available[10], max[10][10], allocation[10][10], need[10][10];

void inputMatrices() { 

    printf("Enter the total resources for each type:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &total[i]);
    }


    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }


    printf("Enter the max matrix:\n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }


    for (int i = 0; i < numResources; i++) {
        available[i] = total[i];  
        for (int j = 0; j < numProcesses; j++) {
            available[i] -= allocation[j][i]; 
        }
    }


    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    bool finished[10] = {false};
    int work[10];
    int safeSequence[10];
    int count = 0;
    

    for (int i = 0; i < numResources; i++) {
        work[i] = available[i];
    }

    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < numResources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finished[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state.\n");
            return false;
        }
    }
    
    printf("System is in a safe state. Safe sequence: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {

    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter number of resources: ");
    scanf("%d", &numResources);

   
    inputMatrices();

    
    isSafe();
    return 0;
}
