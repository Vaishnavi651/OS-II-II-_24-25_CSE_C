#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

void calculateNeed(int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(int n, int m) {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};

    for (int i = 0; i < m; i++)
        work[i] = available[i];

    int safeSeq[MAX_PROCESSES], count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++)
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
   
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return true;
}

bool requestResources(int processID, int request[], int n, int m) {
    for (int i = 0; i < m; i++) {
        if (request[i] > need[processID][i]) {
            printf("Error: Process has exceeded maximum claim.\n");
            return false;
        }
        if (request[i] > available[i]) {
            printf("Process must wait: Not enough available resources.\n");
            return false;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    if (isSafe(n, m))
        return true;
   
    for (int i = 0; i < m; i++) {
        available[i] += request[i];
        allocation[processID][i] -= request[i];
        need[processID][i] += request[i];
    }

    printf("Request cannot be granted, as it leads to an unsafe state.\n");
    return false;
}

int main() {
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    printf("Enter the maximum resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i + 1);
        for (int j = 0; j < m; j++) {
            printf("Max resource %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:\n", i + 1);
        for (int j = 0; j < m; j++) {
            printf("Allocated resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    calculateNeed(n, m);

    if (isSafe(n, m))
    {
        printf("System is initially in a safe state.\n");
    }
    else
    {
        printf("System is in an unsafe state!\n");
    }

    int request[3], processID;
    printf("Enter the process ID requesting resources (0 to %d): ", n - 1);
    scanf("%d", &processID);

    printf("Enter the request for resources (size %d):\n", m);
    for (int i = 0; i < m; i++) {
        printf("Request for resource %d: ", i + 1);
        scanf("%d", &request[i]);
    }

    printf("Process P%d requesting resources: ", processID);
    for (int i = 0; i < m; i++) {
        printf("%d ", request[i]);
    }
    printf("\n");

    if (requestResources(processID, request, n, m))
    {
        printf("Request granted.\n");
    }
    else
    {
        printf("Request denied.\n");
    }
    return 0;
}
