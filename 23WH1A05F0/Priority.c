#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void priorityScheduling(struct Process p[], int n) {
    int time = 0;
    int completed = 0;
    int minPriorityIndex;
    int finished[n];
    for (int i = 0; i < n; i++) finished[i] = 0;

    printf("\nGantt Chart: ");
    printf("\n---------------------------\n");

    while (completed < n) {
        minPriorityIndex = -1;
        int minPriority = 9999;
        
        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= time && finished[i] == 0 && p[i].priority < minPriority) {
                minPriority = p[i].priority;
                minPriorityIndex = i;
            }
        }

        if (minPriorityIndex != -1) {
            printf("P%d ", p[minPriorityIndex].id);
            time += p[minPriorityIndex].burstTime;
            p[minPriorityIndex].completionTime = time;
            p[minPriorityIndex].turnaroundTime = p[minPriorityIndex].completionTime - p[minPriorityIndex].arrivalTime;
            p[minPriorityIndex].waitingTime = p[minPriorityIndex].turnaroundTime - p[minPriorityIndex].burstTime;
            finished[minPriorityIndex] = 1;
            completed++;
        } else {
            time++;  // Increment time if no process is ready to execute
        }
    }

    printf("\n---------------------------\n");

    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].burstTime, p[i].arrivalTime,
                p[i].priority, p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }
}

int main() {
    struct Process p[MAX];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time, burst time, and priority for Process P%d: ", p[i].id);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
    }

    priorityScheduling(p, n);

    return 0;
}

