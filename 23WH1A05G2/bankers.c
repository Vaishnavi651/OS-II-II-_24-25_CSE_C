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
    
    int safe[n], c= 0;

    while (c < n) {
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

bool reqResources(int processID, int request[], int n, int m, int available[], int max[n][m], int allocation[n][m], int need[n][m]) {
    for (int i = 0; i < m; i++) {
        if (request[i] > need[processID][i]) {
            printf("Error-Process exceeded max claim.\n");
            return false;
        }
        if (request[i] > available[i]) {
            printf("Process must wait.\n");
            return false;
        }
    }

    for (int i = 0; i < m; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }

    if (isSafe(n, m, available, max, allocation, need)) {
        return true;
    }

    for (int i = 0; i < m; i++) {
        available[i] += request[i];
        allocation[processID][i] -= request[i];
        need[processID][i] += request[i];
    }

    printf("Request can't be granted(unsafe state)\n");
    return false;
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
       // printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    printf("Enter the max resources for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:(for %d resources)\n",i+1,m);
        for (int j = 0; j < m; j++) {
           // printf("Max resource %d: ", j + 1);
            scanf("%d", &max[i][j]);
        }
    }

   
    printf("Enter the allocation for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("For Process P%d:(for %d resources)\n",i+1,m);
        for (int j = 0; j < m; j++) {
           // printf("Allocated resource %d: ", j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }
    
    calcneed(n, m, max, allocation, need);
    if (isSafe(n, m, available, max, allocation, need))
        printf("System is initially in a safe state.\n");
    else
        printf("System is in an unsafe state\n");

   
    int request[m], processID;
    printf("Enter the process id requesting resources (0 to %d): ", n - 1);
    scanf("%d", &processID);

    printf("Enter the request for resources (size %d):\n",m);
    for (int i = 0; i < m; i++) {
       	printf("Request for resource %d: ", i + 1);
        scanf("%d", &request[i]);
    }

    printf("Process P%d requesting resources: ", processID);
    for (int i = 0; i < m; i++) {
        printf("%d ", request[i]);
    }
    printf("\n");

    if (reqResources(processID, request, n, m, available, max, allocation, need))
        printf("Request granted.\n");
    else
        printf("Request denied.\n");

    return 0;
}

