#include <stdio.h>
struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int arrivalTime;
};
void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}
void calculateWaitingTime(struct Process processes[], int n) {
    int completeTime[n];
    completeTime[0] = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        if (completeTime[i-1] < processes[i].arrivalTime) {
            completeTime[i] = processes[i].arrivalTime + processes[i].burstTime;
            processes[i].waitingTime = 0; 
        } else {
            processes[i].waitingTime = completeTime[i-1] - processes[i].arrivalTime;
            completeTime[i] = completeTime[i-1] + processes[i].burstTime;
        }
    }
}

void findavgTime(struct Process processes[], int n) {
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;
    printf("\nPID\tBTime\tATime\tWTime\tTATime\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, processes[i].burstTime, 
               processes[i].arrivalTime, processes[i].waitingTime, 
               processes[i].turnaroundTime);
    }
    printf("\nAverage waiting time: %.2f", totalWaitingTime / n);
    printf("\nAverage turnaround time: %.2f\n", totalTurnaroundTime / n);
}
void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime ||
               (processes[j].arrivalTime == processes[j + 1].arrivalTime && processes[j].burstTime > processes[j + 1].burstTime)) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; 
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrivalTime);
    }
    sortProcesses(processes, n);
    findavgTime(processes, n);
    
    return 0;
}
