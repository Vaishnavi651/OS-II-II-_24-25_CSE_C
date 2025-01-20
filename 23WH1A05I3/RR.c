#include <stdio.h>

int main() {
    int n, bt[10], at[10], wt[10], tat[10], ct[10], p[10], sum, i, j, k, temp;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }


   
    printf("Enter the arrival times of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

  
    printf("Enter the burst times of each process: ");
    for (i = 0; i < n; i++) {
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
       avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\t WT\tTAT\tCT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t     %d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}

