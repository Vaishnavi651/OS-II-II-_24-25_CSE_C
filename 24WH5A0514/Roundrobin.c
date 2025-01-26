#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int findNextProcess(struct Process p[], int n, int quantum) {
    for (int i = 0; i < n; i++) {
        if (p[i].remainingTime > 0) {
            return i;
        }
    }
    return -1;
}

void roundRobin(struct Process p[], int n, int quantum) {
    int time = 0;
    int completed = 0;
    printf("\nGantt Chart: ");
    printf("\n---------------------------\n");
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remainingTime > 0) {
                printf("P%d ", p[i].id);
                if (p[i].remainingTime > quantum) {
                    time += quantum;
                    p[i].remainingTime -= quantum;
                } else {
                    time += p[i].remainingTime;
                    p[i].remainingTime = 0;
                    p[i].completionTime = time;
                    p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
                    completed++;
                }
            }
        }
    }
    printf("\n---------------------------\n");

    printf("\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burstTime, p[i].arrivalTime,
                p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }
}

void displayReadyQueue(struct Process p[], int n) {
    printf("\nReady Queue at each step: \n");
    for (int i = 0; i < n; i++) {
        if (p[i].remainingTime > 0) {
            printf("P%d ", p[i].id);
        }
    }
    printf("\n");
}

int main() {
    struct Process p[MAX];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for Process P%d: ", p[i].id);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].remainingTime = p[i].burstTime;
    }

    roundRobin(p, n, quantum);
    displayReadyQueue(p, n);

    return 0;
}
