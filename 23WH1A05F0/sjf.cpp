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

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (bt[j] > bt[j+1] || bt[j]==bt[j+1] && at[j]>at[j+1]) {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    sum = 0;
    for (j = 0; j < n; j++) {
        if (j == 0 || ct[j-1] < at[j]) {
            ct[j] = at[j] + bt[j];
        } else {
            ct[j] = ct[j-1] + bt[j];
        }
    }

    for (k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        totaltat = totaltat + tat[k];
    }

    for (k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        if (wt[k] < 0) {
            wt[k] = 0;
        }
        totalwt = totalwt + wt[k];
    }

    printf("\nProcessID\tArrivalTime\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", totaltat / n);
    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);


}
