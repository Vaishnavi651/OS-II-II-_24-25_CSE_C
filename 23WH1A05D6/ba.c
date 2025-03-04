#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
bool canExecute(int process, int need[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES], int resources) {
    for (int j = 0; j < resources; j++) {
        if (need[process][j] > available[j]) {
            return false;
        }
    }
    return true;
}
void bankersAlgorithm(int processes, int resources, int allocation[MAX_PROCESSES][MAX_RESOURCES],
                      int max[MAX_PROCESSES][MAX_RESOURCES], int available[MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];
    int count = 0;
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    while (count < processes) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i] && canExecute(i, need, work, resources)) {
                for (int j = 0; j < resources; j++) {
                    work[j] += allocation[i][j];
                }
                safeSequence[count++] = i;
                finish[i] = true;
                found = true;
            }
        }
        if (!found) {
            printf("The system is in an unsafe state! Deadlock occurred.\n");
            return;
        }
    }
    printf("The system is in a safe state.\nSafe Sequence: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\nNo deadlock occurred.\n");
}
int main() {
    int processes, resources;
    int allocation[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES];
    int total[MAX_RESOURCES], available[MAX_RESOURCES];
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);
    printf("Enter total instances of each resource:\n");
    for (int j = 0; j < resources; j++) {
        scanf("%d", &total[j]);
    }
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter Maximum Requirement Matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    for (int j = 0; j < resources; j++) {
        int sum = 0;
        for (int i = 0; i < processes; i++) {
            sum += allocation[i][j];
        }
        available[j] = total[j] - sum;
    }
    bankersAlgorithm(processes, resources, allocation, max, available);
    return 0;
} 
