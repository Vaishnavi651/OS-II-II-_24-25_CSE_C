#include <stdio.h>

int main() {
    int n, bt[10], at[10], wt[10], tat[10], ct[10], p[10], sum, i, j, k, temp;
    float totaltat = 0, totalwt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int qt;
    printf("Enter the Quantum time: ");
    scanf("%d", &qt);

    int rem_bt[n];
    for (i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0;
    int completed = 0;
    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                if (rem_bt[i] > qt) {
                    t += qt;
                    rem_bt[i] -= qt;
                } else {
                    t += rem_bt[i];
                    ct[i] = t;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        totaltat += tat[i];
        totalwt += wt[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);

    return 0;
}

