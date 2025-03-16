#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES], available[MAX_RESOURCES];
int processCount, resourceCount;

void inputDetails() {
    printf("Enter the number of processes: ");
    scanf("%d", &processCount);
    printf("Enter the number of resources: ");
    scanf("%d", &resourceCount);

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < processCount; i++)
        for (int j = 0; j < resourceCount; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < processCount; i++)
        for (int j = 0; j < resourceCount; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j]; 
        }

    printf("Enter Available Resources:\n");
    for (int i = 0; i < resourceCount; i++)
        scanf("%d", &available[i]);
}

int isSafe() {
    int finish[MAX_PROCESSES] = {0}; 
    int safeSequence[MAX_PROCESSES], work[MAX_RESOURCES];

    
    for (int i = 0; i < resourceCount; i++)
        work[i] = available[i];

    int count = 0;
    while (count < processCount) {
        int found = 0;
        for (int i = 0; i < processCount; i++) {
            if (!finish[i]) { 
                int canExecute = 1;
                for (int j = 0; j < resourceCount; j++) {
                    if (need[i][j] > work[j]) { 
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    
                    for (int j = 0; j < resourceCount; j++)
                        work[j] += allocation[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state! Deadlock may occur.\n");
            return 0;
        }
    }

    
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < processCount; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");
    return 1;
}

int main() {
    inputDetails();
    isSafe();
    return 0;
}
