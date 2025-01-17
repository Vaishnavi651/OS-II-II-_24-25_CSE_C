#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    int pid[n], burstTime[n], waitingTime[n], turnAroundTime[n], remainingTime[n];
    int currentTime = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
        waitingTime[i] = 0;
    }
    
    while (completed < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                executed = 1;
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i];
                    turnAroundTime[i] = waitingTime[i] + burstTime[i];
                    remainingTime[i] = 0;
                    completed++;
                    totalWaitingTime += waitingTime[i];
                    totalTurnAroundTime += turnAroundTime[i];
                }
            }
        }
        if (!executed) {
            currentTime++;
        }
    }
    
    printf("\nProcesses\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
    
    printf("\nAverage waiting time = %.2f\n", totalWaitingTime / n);
    printf("Average turn-around time = %.2f\n", totalTurnAroundTime / n);
    
    return 0;
}
