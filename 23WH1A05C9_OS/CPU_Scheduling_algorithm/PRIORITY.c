//Priority
#include <stdio.h>

// Function to calculate waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[], int pr[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0; // First process has no waiting time

    // Calculate waiting time for all other processes
    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + bt[i - 1];
        wt[i] = service_time[i] - at[i];

        // If waiting time is negative, reset it to 0
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

// Function to calculate turn-around time for all processes
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to calculate average times and display process information
void findAvgTime(int processes[], int n, int bt[], int at[], int pr[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting and turn-around times
    findWaitingTime(processes, n, bt, wt, at, pr);
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display process information
    printf("Processes\tBurst Time\tWaiting Time\tTurn-Around Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i], bt[i], wt[i], tat[i], pr[i]);
    }

    // Display average times
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn-around time = %.2f\n", (float)total_tat / n);
}

// Function to implement Priority Scheduling (non-preemptive)
void priorityScheduling(int processes[], int n, int bt[], int at[], int pr[]) {
    int temp;

    // Sort processes by priority (higher priority = smaller number)
    // If priorities are equal, sort by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[i] > pr[j] || (pr[i] == pr[j] && at[i] > at[j])) {
                // Swap arrival times
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap priorities
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap process numbers
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Calculate and display average times
    findAvgTime(processes, n, bt, at, pr);
}

// Main function
int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n], priority[n];

    // Input burst time, arrival time, and priority for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Call Priority Scheduling function
    priorityScheduling(processes, n, burst_time, arrival_time, priority);

    return 0;
}
