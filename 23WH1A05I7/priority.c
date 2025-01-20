#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], at[10], pr[10], wt[10], tat[10], completed[10], process[10];
    float total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time, arrival time, and priority for each process
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &pr[i]);
        process[i] = i + 1; // Process ID
        completed[i] = 0;   // Initialize as not completed
    }

    // Sort processes by priority (and arrival time if priority is the same)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {
                // Swap priority
                int temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap process ID
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    // Initialize current time
    int time = 0;

    // Calculate waiting time and turn-around time
    for (i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i]; // Wait for the process to arrive
        }

        wt[i] = time - at[i]; // Waiting time
        if (wt[i] < 0) {
            wt[i] = 0; // Ensure waiting time is not negative
        }

        time += bt[i]; // Update current time
        tat[i] = wt[i] + bt[i]; // Turn-around time

        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display results
    printf("\nProcesses\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], pr[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Display average waiting time and turn-around time
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", total_tat / n);

    return 0;
}
