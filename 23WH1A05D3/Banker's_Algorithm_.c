#include <stdio.h>
#include <stdbool.h>

#define MAX 10
#define RESOURCE_TYPES 3

int processes, resources;
int allocation[MAX][RESOURCE_TYPES], maximum[MAX][RESOURCE_TYPES], need[MAX][RESOURCE_TYPES];
int available[RESOURCE_TYPES], safeSequence[MAX];
bool isSafe() {
    int work[RESOURCE_TYPES];
    bool finish[MAX] = {0};
    int count = 0;
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }

    while (count < processes) {
        bool found = false;

        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == resources) {
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            return false;
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
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    printf("\nEnter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
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
