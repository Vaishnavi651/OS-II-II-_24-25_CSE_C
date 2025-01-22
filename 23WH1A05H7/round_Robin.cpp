#include <stdio.h>
#define MAX 100
int main() {
    int n, timeQuantum,i;
    int burstTime[MAX], arrivalTime[MAX], waitingTime[MAX], turnAroundTime[MAX], remainingBurstTime[MAX], completionTime[MAX];
    int pid[MAX]; // Process IDs
    int totalWaitingTime = 0, totalTurnAroundTime = 0, currentTime = 0, processesRemaining;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        remainingBurstTime[i] = burstTime[i]; 
        waitingTime[i] = 0; 
        completionTime[i] = 0; 
    }
    
    processesRemaining = n;
    while (processesRemaining > 0) {
        for (i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && remainingBurstTime[i] > 0) {
                if (remainingBurstTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingBurstTime[i] -= timeQuantum;
                } else {
                    currentTime += remainingBurstTime[i];
                    completionTime[i] = currentTime; 
                    waitingTime[i] = currentTime - burstTime[i] - arrivalTime[i];
                    if (waitingTime[i] < 0) {
                        waitingTime[i] = 0; 
                    }
                    turnAroundTime[i] = waitingTime[i] + burstTime[i];
                    remainingBurstTime[i] = 0; 
                    processesRemaining--; 
                }
            }
        }
    }
    for ( i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    printf("\nProcesses\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burstTime[i], arrivalTime[i], completionTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage waiting time = %.2f\n", (float)totalWaitingTime / n);
    printf("Average turn-around time = %.2f\n", (float)totalTurnAroundTime / n);
    
    return 0;
}

