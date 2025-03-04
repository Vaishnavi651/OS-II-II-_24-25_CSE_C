#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

void inputMatrices(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
                   int max[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES]);
void calculateNeed(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
                   int max[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES]);
int isSafe(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
           int need[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int safeSequence[MAX_PROCESSES]);
void printSafeSequence(int processes, int safeSequence[MAX_PROCESSES]);
void printMatrix(int processes, int resources, int matrix[MAX_PROCESSES][MAX_RESOURCES], char *title);
void printAvailable(int resources, int available[MAX_RESOURCES]);

int main() {
    int processes, resources;
    int allocated[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES], available[MAX_RESOURCES];
    int safeSequence[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    inputMatrices(processes, resources, allocated, max, available);
    calculateNeed(processes, resources, allocated, max, need);

    printf("\nNeed Matrix:\n");
    printMatrix(processes, resources, need, "Need");
    
    if (isSafe(processes, resources, allocated, need, available, safeSequence)) {
        printSafeSequence(processes, safeSequence);
    } else {
        printf("\nThe system is in an unsafe state (Deadlock possible).\n");
    }

    return 0;
}

void inputMatrices(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
                   int max[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES]) {
    int i, j;

    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &allocated[i][j]);
        }
    }

    printf("\nEnter the Maximum Matrix:\n");
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter the Available Resources:\n");
    for (i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
}

void calculateNeed(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
                   int max[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES]) {
    int i, j;
    for (i = 0; i < processes; i++) {
        for (j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
}

int isSafe(int processes, int resources, int allocated[MAX_PROCESSES][MAX_RESOURCES], 
           int need[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int safeSequence[MAX_PROCESSES]) {
    int finished[MAX_PROCESSES] = {0};  
    int work[MAX_RESOURCES];  
    int i, j, count = 0;

    for (i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    while (count < processes) {
        int found = 0;
        for (i = 0; i < processes; i++) {
            if (!finished[i]) { 
                int canAllocate = 1;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (j = 0; j < resources; j++) {
                        work[j] += allocated[i][j]; 
                    }
                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                    
                    printf("\nAfter allocating process P%d:\n", i);
                    printAvailable(resources, work);
                }
            }
        }

        if (!found) { 
            return 0;
        }
    }
    return 1;
}

void printSafeSequence(int processes, int safeSequence[MAX_PROCESSES]) {
    printf("\nThe system is in a safe state.\nSafe Sequence: < ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf(">\n");
}

void printMatrix(int processes, int resources, int matrix[MAX_PROCESSES][MAX_RESOURCES], char *title) {
    printf("%s Matrix:\n", title);
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printAvailable(int resources, int available[MAX_RESOURCES]) {
    printf("Available Resources: ");
    for (int i = 0; i < resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}
