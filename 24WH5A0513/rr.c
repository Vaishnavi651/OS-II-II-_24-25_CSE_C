#include <stdio.h>

struct Process {
    int id;        
    int bt;        
    int wt;        
    int tat;      
};

void findWaitingTime(struct Process proc[], int n, int bt[], int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = bt[i];
        proc[i].wt = 0;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0;
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    proc[i].wt = time - bt[i];
                    remainingTime[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
}

void findTurnaroundTime(struct Process proc[], int n, int bt[]) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = bt[i] + proc[i].wt;
    }
}

void findAvgTime(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }
    printf("\nAverage waiting time: %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time: %.2f", (float)total_tat / n);
}

void roundRobin(struct Process proc[], int n, int bt[], int quantum) {
    findWaitingTime(proc, n, bt, quantum);
    findTurnaroundTime(proc, n, bt);
    findAvgTime(proc, n);
}

int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
   
    struct Process proc[n];
    int bt[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nEnter Burst time for Process %d: ", proc[i].id);
        scanf("%d", &bt[i]);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    roundRobin(proc, n, bt, quantum);

    return 0;
}
