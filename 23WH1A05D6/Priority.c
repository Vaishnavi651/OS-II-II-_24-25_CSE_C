#include <stdio.h>
#include <stdlib.h>

struct process {
    int process_id;
    int burst_time;
    int priority;
    int arrival_time; // Added arrival time
    int waiting_time;
    int turnaround_time;
    int completion_time; // Added completion time
};

void find_waiting_time(struct process[], int, int[]);
void find_turnaround_time(struct process[], int, int[], int[]);
void sort_processes(struct process[], int);


void priority_scheduling(struct process[], int);

int main() {
    int n, i;
    struct process proc[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the process ID: ");
        scanf("%d", &proc[i].process_id);
        printf("Enter the burst time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &proc[i].priority);
        printf("Enter the arrival time: ");
        scanf("%d", &proc[i].arrival_time); // Added arrival time input
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
        proc[i].completion_time = 0; // Initialize completion time
    }

    sort_processes(proc, n); //Sort processes by arrival time
    priority_scheduling(proc, n);
    return 0;
}

void find_waiting_time(struct process proc[], int n, int wt[]) {
    int i;
    wt[0] = 0; //first process waiting time is 0
    for (i = 1; i < n; i++) {
        wt[i] = proc[i - 1].completion_time - proc[i].arrival_time;
        if (wt[i] < 0) wt[i] = 0; //waiting time can't be negative

    }
}

void find_turnaround_time(struct process proc[], int n, int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++) {
        tat[i] = proc[i].burst_time + wt[i];
        proc[i].completion_time = proc[i].arrival_time + tat[i]; //calculate completion time
    }
}

void sort_processes(struct process proc[], int n) {
    int i, j;
    struct process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}


void priority_scheduling(struct process proc[], int n) {
    int i, j, pos;
    struct process temp;
    int wt[10], tat[10];

    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (proc[j].priority < proc[pos].priority) {
                pos = j;
            }
        }
        temp = proc[i];
        proc[i] = proc[pos];
        proc[pos] = temp;
    }

    find_waiting_time(proc, n, wt);
    find_turnaround_time(proc, n, wt, tat);

    printf("\nProcess ID\tBurst Time\tPriority\tArrival Time\tWaiting Time\tTurnaround Time\tCompletion Time");
    float total_wt = 0, total_tat = 0;
    for (i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].process_id, proc[i].burst_time, proc[i].priority, proc[i].arrival_time, wt[i], tat[i], proc[i].completion_time);
    }

    printf("\n\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

