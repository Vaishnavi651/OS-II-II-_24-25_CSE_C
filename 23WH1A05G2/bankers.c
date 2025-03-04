#include <stdio.h>
#include <stdbool.h>

void calcneed(int n, int m, int max[n][m], int allocation[n][m], int need[n][m]) {
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
    
    int safe[n],c=0;

    while (c<n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool allocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        allocate = false;
                        break;
                    }
                }
                if (allocate) {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safe[c++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            return false;
    }
    
    printf("safe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safe[i]);
    printf("\n");

    return true;
}

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    int available[m];
    int max[n][m], allocation[n][m], need[n][m];
    printf("Enter the available resources:(for %d resources)\n",m);
    for (int i = 0; i < m; i++) {
       
        scanf("%d", &available[i]);
    }
    printf("Enter the max resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:(for %d resources)\n",i+1,m);
        for (int j = 0; j < m; j++) {
             scanf("%d", &max[i][j]);
        }
    }   
    printf("Enter the allocation for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:(for %d resources)\n",i+1,m);
        for (int j = 0; j < m; j++) {
                scanf("%d", &allocation[i][j]);
        }
    }
    
    calcneed(n, m, max, allocation, need);
    if (isSafe(n, m, available, max, allocation, need))
        printf("System is initially in a safe state.\n");
    else
        printf("System is in an unsafe state\n");
    return 0;
}

