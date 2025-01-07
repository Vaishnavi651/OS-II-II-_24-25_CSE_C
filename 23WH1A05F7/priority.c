#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void findWaitingTime(struct Process proc[], int n, int bt[], int wt[], int quantum) {
    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0) {
                done = 0;
                if (proc[i].remainingTime > quantum) {
                    t += quantum;
                    proc[i].remainingTime -= quantum;
                } else {
                    t += proc[i].remainingTime;
                    wt[i] = t - bt[i];
                    proc[i].remainingTime = 0;
                }
            }
        }
        if (done == 1) break;
    }
}

void findTurnaroundTime(struct Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(struct Process proc[], int n, int quantum) {
    int bt[n], wt[n], tat[n];
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burstTime;
        proc[i].remainingTime = bt[i];
    }
    findWaitingTime(proc, n, bt, wt, quantum);
    findTurnaroundTime(proc, n, bt, wt, tat);
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += wt[i];
        totalTurnaroundTime += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

void printGanttChart(struct Process proc[], int n, int quantum) {
    int t = 0;
    printf("Gantt Chart:\n");
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].remainingTime > 0) {
                done = 0;
                if (proc[i].remainingTime > quantum) {
                    printf("| P%d ", proc[i].id);
                    t += quantum;
                    proc[i].remainingTime -= quantum;
                } else {
                    printf("| P%d ", proc[i].id);
                    t += proc[i].remainingTime;
                    proc[i].remainingTime = 0;
                }
            }
        }
        if (done == 1) break;
    }
    printf("|\n");
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burstTime);
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    findavgTime(proc, n, quantum);
    printGanttChart(proc, n, quantum);
    return 0;
}
