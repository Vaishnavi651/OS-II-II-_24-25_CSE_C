#include <stdio.h>
struct process {
    int id;             // Process ID
    int bt;             // Burst time (execution time)
    int wt;             // Waiting time
    int tat;            // Turnaround time
    int priority;       // Process priority
};
void findWaitingTime(struct process proc[], int n) {
    proc[0].wt = 0;  // Waiting time for the first process is 0

    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;  // Waiting time = burst time of previous + waiting time of previous
    }
}

void findTurnaroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;  // Turnaround time = burst time + waiting time
    }
}
void findAverageTime(struct process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}
void sortByPriority(struct process proc[], int n) {
    struct process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                // Swap the processes based on priority
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}
void display(struct process proc[], int n) {
    printf("\nPID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
}
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;  // Process ID
        printf("\nEnter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &proc[i].bt, &proc[i].priority);
    }

    sortByPriority(proc, n);
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);
    display(proc, n);
    findAverageTime(proc, n);
    return 0;
}

      
    find_average_time(proc, n);  
    }  
