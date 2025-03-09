#include <stdio.h>
#include <stdbool.h>

#define MAX_RESOURCES 10
#define MAX_PROCESSES 10

int Available[MAX_RESOURCES], Max[MAX_PROCESSES][MAX_RESOURCES], Allocation[MAX_PROCESSES][MAX_RESOURCES], Need[MAX_PROCESSES][MAX_RESOURCES];
int resources, processes;

void calculateNeed() {
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            Need[i][j] = Max[i][j] - Allocation[i][j];
}

bool isSafe() {
    int Work[MAX_RESOURCES], safeSeq[MAX_PROCESSES], index = 0;
    bool Finish[MAX_PROCESSES] = {false};
    
    for (int j = 0; j < resources; j++)
        Work[j] = Available[j];

    printf("\nAvailable Resources: ");
    for (int j = 0; j < resources; j++)
        printf("%d ", Available[j]);
    printf("\n");

    while (true) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!Finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resources; j++) {
                    if (Need[i][j] > Work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < resources; j++)
                        Work[j] += Allocation[i][j];  // Release resources
                    Finish[i] = true;
                    safeSeq[index++] = i;
                    found = true;
                    printf("Process P%d executed, new Available: ", i);
                    for (int j = 0; j < resources; j++)
                        printf("%d ", Work[j]);
                    printf("\n");
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < processes; i++) {
        if (!Finish[i]) {
            printf("\n🚨 System is NOT in a safe state! Deadlock detected.\n");
            return false;
        }
    }
    
    printf("\n✅ System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < processes; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    
    return true;
}

void takeInput() {
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    int Total[MAX_RESOURCES];
    printf("Enter total instances of each resource: ");
    for (int j = 0; j < resources; j++)
        scanf("%d", &Total[j]);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &Allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &Max[i][j]);

    for (int j = 0; j < resources; j++) {
        int sum = 0;
        for (int i = 0; i < processes; i++)
            sum += Allocation[i][j];
        Available[j] = Total[j] - sum;
    }
    calculateNeed();
}

int main() {
    takeInput();
    isSafe();
    return 0;
}
