#include <stdio.h>
#include <stdbool.h>
#define N 5 
#define M 3 
int Available[M];          
int Max[N][M];               
int Allocation[N][M];      
int Need[N][M];              
void calculateNeed() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
}
bool isSafe() {
    int Work[M];
    bool Finish[N] = {false}; 
    int safeSeq[N], index = 0;
    for (int j = 0; j < M; j++)
        Work[j] = Available[j];
    while (true) {
        bool found = false;
        for (int i = 0; i < N; i++) {
            if (!Finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < M; j++) {
                    if (Need[i][j] > Work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < M; j++)
                        Work[j] += Allocation[i][j];
                    Finish[i] = true;
                    safeSeq[index++] = i;
                    found = true;
                }
            }
        }
        if (!found) break;
    }
    for (int i = 0; i < N; i++) {
        if (!Finish[i]) {
            printf("System is NOT in a safe state!\n");
            return false;
        }
    }
    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < N; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return true;
}
bool requestResources(int process, int request[]) {
    for (int j = 0; j < M; j++) {
        if (request[j] > Need[process][j]) {
            printf("Error: Process P%d requested more than its maximum claim.\n", process);
            return false;
        }
    }
    for (int j = 0; j < M; j++) {
        if (request[j] > Available[j]) {
            printf("Process P%d must wait. Not enough resources available.\n", process);
            return false;
        }
    }

    
    for (int j = 0; j < M; j++) {
        Available[j] -= request[j];
        Allocation[process][j] += request[j];
        Need[process][j] -= request[j];
    }

    
    if (isSafe()) {
        printf("Resources allocated successfully to P%d.\n", process);
        return true;
    } else {
       
        for (int j = 0; j < M; j++) {
            Available[j] += request[j];
            Allocation[process][j] -= request[j];
            Need[process][j] += request[j];
        }
        printf("Request denied for P%d to avoid unsafe state.\n", process);
        return false;
    }
}


void takeInput() {
    printf("Enter Available Resources: ");
    for (int j = 0; j < M; j++)
        scanf("%d", &Available[j]);

    printf("Enter Maximum Resource Matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &Allocation[i][j]);

    calculateNeed();
}


int main() {
    takeInput();

    printf("\nInitial System State:\n");
    isSafe(); 

    
    int process;
    int request[M];

    printf("\nEnter process number (0 to %d) requesting resources: ", N - 1);
    scanf("%d", &process);

    printf("Enter request for process P%d: ", process);
    for (int i = 0; i < M; i++)
        scanf("%d", &request[i]);

    requestResources(process, request);

    return 0;
}
