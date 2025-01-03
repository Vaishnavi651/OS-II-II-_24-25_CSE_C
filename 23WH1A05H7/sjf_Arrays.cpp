#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(int pid[], int burstTime[], int arrivalTime[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burstTime[j] > burstTime[j + 1] ||
               (burstTime[j] == burstTime[j + 1] && arrivalTime[j] > arrivalTime[j + 1])) {
                swap(&pid[j], &pid[j + 1]);
                swap(&burstTime[j], &burstTime[j + 1]);
                swap(&arrivalTime[j], &arrivalTime[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int pid[n], burstTime[n], arrivalTime[n], waitingTime[n], turnAroundTime[n];
    
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }
    sortProcesses(pid, burstTime, arrivalTime, n);
    
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentTime < arrivalTime[i]) {
            currentTime = arrivalTime[i];
        }
        
        waitingTime[i] = currentTime - arrivalTime[i];
        if (waitingTime[i] < 0) waitingTime[i] = 0;
        
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
        
        currentTime += burstTime[i];
        
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    
    printf("\nProcesses\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], burstTime[i], arrivalTime[i], waitingTime[i], turnAroundTime[i]);
    }
    
    printf("\nAverage waiting time = %.2f\n", (float)totalWaitingTime / n);
    printf("Average turn-around time = %.2f\n", (float)totalTurnAroundTime / n);
    
    return 0;
}

