#include <stdio.h>

int main() {
    int n, tq, i, time = 0, remaining;
    int bt[10], at[10], rt[10], wt[10], tat[10];
    float total_wt = 0, total_tat = 0;

    // Input number of processes and time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    // Input burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        rt[i] = bt[i]; // Initialize remaining time to burst time
    }

    remaining = n; // Number of unfinished processes

    // Initialize waiting and turn-around time
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    // Round Robin Scheduling
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) { // If process is available to execute
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    remaining--;
                    tat[i] = time - at[i];      
                    wt[i] = tat[i] - bt[i];     
                }
            }
        }
    }

   
    for (i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

   
    printf("\nProcesses\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", total_tat / n);

    return 0;
}

