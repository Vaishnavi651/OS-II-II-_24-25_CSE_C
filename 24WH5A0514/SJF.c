#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

int compare(const void *a, const void *b) {
    return ((Process *)a)->burstTime - ((Process *)b)->burstTime;
}

void calculateTimes(Process *processes, int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    processes[0].waitingTime = 0; 

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\nAverage Waiting Time = %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time = %.2f", (float)totalTurnaroundTime / n);
}

void displayProcesses(Process *processes, int n) {
    printf("\nPID\tBurstTime\tWaitingTime\tTurnaroundTime\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].processID, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
   for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;  
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }
   qsort(processes, n, sizeof(Process), compare);
    calculateTimes(processes, n);
    displayProcesses(processes, n);
return 0;
}
