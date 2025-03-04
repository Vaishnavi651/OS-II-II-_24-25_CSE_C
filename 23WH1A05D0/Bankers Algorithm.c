#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int n; 
int m;

int max[MAX_PROCESSES][MAX_RESOURCES]; 
int allot[MAX_PROCESSES][MAX_RESOURCES]; 
int avail[MAX_RESOURCES]; 
int need[MAX_PROCESSES][MAX_RESOURCES]; 

void calculateNeed() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = {false};
    int safeSeq[MAX_PROCESSES];
    int count = 0;

    for (int i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
                if (j == m) {
                    for (int k = 0; k < m; k++) {
                        work[k] += allot[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < count; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

void printNeed() {
    printf("Need matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter maximum resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter currently allocated resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    calculateNeed();
    printNeed();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (need[i][j] < 0) {
                printf("System is not in a safe state.\n");
                return 0;
            }
        }
    }

    isSafe();
   

    return 0;
}
