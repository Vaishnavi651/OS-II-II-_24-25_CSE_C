#include <stdio.h>

int main() {
    int p[100], at[100], bt[100], pr[100], ct[100], tat[100], wt[100], completed[100] = {0};
    int n, i, currentTime = 0, completedCount = 0;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process IDs: ");
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

    printf("Enter the priorities of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    while (completedCount < n) {
        int minIndex = -1;

        for (i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= currentTime && 
                (minIndex == -1 || pr[i] < pr[minIndex])) {
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            currentTime++;
            continue;
        }

        currentTime += bt[minIndex];
        ct[minIndex] = currentTime;
        completed[minIndex] = 1;
        completedCount++;
    }
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nProcess  AT      BT      Priority   CT      TAT     WT");
    for (i = 0; i < n; i++) {
        printf("\nP%-8d%-8d%-8d%-8d%-8d%-8d%-8d", p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Turnaround Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt / n);

return 0;
}
