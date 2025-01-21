#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, i, time = 0, completed = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], rt[n];
    bool done[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
        done[i] = false;
    }

    while (completed < n) {
        int shortest = -1;
        for (i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time && (shortest == -1 || rt[i] < rt[shortest]))
                shortest = i;
        }

        if (shortest == -1) {
            time++;
        } else {
            time += rt[shortest];
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            done[shortest] = true;
            completed++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
