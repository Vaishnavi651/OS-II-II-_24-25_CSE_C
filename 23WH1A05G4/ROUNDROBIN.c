#include <stdio.h>

int main() {
    int n, i, qt, t = 0, completed = 0;
    int p[10], at[10], bt[10], rem_bt[10], ct[10], tat[10], wt[10];
    float total_tat = 0, total_wt = 0;

    // Input: Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input: Process IDs
    printf("\nEnter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Input: Arrival Times
    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Input: Burst Times
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    // Input: Time Quantum
    printf("Enter the time quantum: ");
    scanf("%d", &qt);

    // Round Robin Scheduling Loop
    while (completed < n) {
        int idle = 1; // Assume CPU is idle initially

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) { // Process is available
                idle = 0; // CPU is now running

                if (rem_bt[i] > qt) {
                    t += qt;        // Execute process for time quantum
                    rem_bt[i] -= qt; // Reduce remaining burst time
                } else {
                    t += rem_bt[i];  // Complete process
                    ct[i] = t;       // Store completion time
                    tat[i] = ct[i] - at[i]; // Turnaround Time
                    wt[i] = tat[i] - bt[i]; // Waiting Time
                    rem_bt[i] = 0;   // Process is completed
                    completed++;
                }
            }
        }
    if (idle) { // If no process is ready, move time forward
            t++;
        }
    }
    // Calculate Average Turnaround Time & Waiting Time
    for (i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Display Results
    printf("\nProcess\tAT\tBT\tWT\tTAT\tCT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    // Print Averages
    printf("\n\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

return 0;
}
