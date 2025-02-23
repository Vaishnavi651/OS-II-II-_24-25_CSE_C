#include <stdio.h>

int main() {
    int p[100], at[100], bt[100], pr[100], ct[100], tat[100], wt[100], completed[100] = {0};
    int n, i, currentTime = 0, completedCount = 0;
    float avg_tat = 0, avg_wt = 0;

    // Input: Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input: Process IDs
    printf("Enter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Input: Arrival Times
    printf("Enter the arrival times of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Input: Burst Times
    printf("Enter the burst times of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Input: Priorities
    printf("Enter the priorities of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    // Priority Scheduling Logic (Non-Preemptive)
    while (completedCount < n) {
        int minIndex = -1;

        // Find the highest priority process that has arrived (lower number = higher priority)
        for (i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= currentTime && 
                (minIndex == -1 || pr[i] < pr[minIndex])) {
                minIndex = i;
            }
        }

        // If no process is ready, move time forward
        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        // Execute the selected process
        currentTime += bt[minIndex];
        ct[minIndex] = currentTime;
        completed[minIndex] = 1; // Mark as completed
        completedCount++;
    }

    // Calculate Turnaround Time and Waiting Time
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    // Display Results
    printf("\nProcess  AT      BT      Priority   CT      TAT     WT");
    for (i = 0; i < n; i++) {
        printf("\nP%-8d%-8d%-8d%-8d%-8d%-8d%-8d", p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    // Print Averages
    printf("\n\nAverage Turnaround Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

return 0;
}
