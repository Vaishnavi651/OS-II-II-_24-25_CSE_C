#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remaining;
    int bt[10], at[10], rt[10], wt[10], tat[10], completed[10] = {0};
    float total_wt = 0, total_tat = 0;

    // Input number of processes and time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Input burst time and arrival time for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time initially equals burst time
    }

    remaining = n; // Number of unfinished processes

    // Round Robin Scheduling
    while (remaining > 0) {
        int executed = 0; // Check if at least one process executed in this cycle

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) { // Process is available
                executed = 1; // At least one process is executed
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    remaining--; // Process finished
                    tat[i] = time - at[i];       // Turn-around time
                    wt[i] = tat[i] - bt[i];      // Waiting time
                    completed[i] = 1; // Mark process as completed
                }
            }
        }

        // If no process was executed, increment time (CPU is idle)
        if (!executed) {
            time++;
        }
    }

    // Calculate total waiting time and turn-around time
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display process details
    printf("\nProcesses\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    // Display averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", total_tat / n);

    return 0;
}

