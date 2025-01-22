#include <stdio.h>

void roundRobin(int processes[], int n, int burstTime[], int quantum) {
    int remainingTime[n], waitingTime[n], turnAroundTime[n];
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    int time = 0;
    int completed = 0;
    
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - burstTime[i];
                    turnAroundTime[i] = time;
                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turn Around Time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n];
    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, burstTime, quantum);
    return 0;
}
