#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int n, int m, int max[n][m], int allocation[n][m], int need[n][m]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(int n, int m, int available[m], int max[n][m], int allocation[n][m], int need[n][m]) {
    int work[m];
    bool finish[n];
   
    for (int i = 0; i < m; i++)
        work[i] = available[i];
   
    for (int i = 0; i < n; i++)
        finish[i] = false;
   
    int safeSeq[n], count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
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


int main() {
    int n, m;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int available[m];
    int max[n][m], allocation[n][m], need[n][m];

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

    calculateNeed(n, m, max, allocation, need);


    if (isSafe(n, m, available, max, allocation, need))
        printf("System is initially in a safe state.\n");
    else
        printf("System is in an unsafe state!\n");

    return 0;
}
