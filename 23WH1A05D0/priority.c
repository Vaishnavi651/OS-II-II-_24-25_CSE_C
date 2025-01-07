#include <stdio.h>
#include <stdlib.h>

void sort(int n, int p[], int at[], int bt[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && priority[i] > priority[j])) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], priority[n], ct[n], tt[n], wt[n];
    int total_wt = 0, total_tt = 0;

    printf("Enter arrival time, burst time, and priority of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Process P%d: ", p[i]);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
    }

    sort(n, p, at, bt, priority);

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        ct[i] = current_time + bt[i];
        current_time = ct[i];
    }

    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
    }

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tt += tt[i];
    }

    printf("\nProcesses    Arrival Time    Burst Time    Priority    Completion Time    Turnaround Time    Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d           %d              %d              %d            %d                %d               %d\n",
               p[i], at[i], bt[i], priority[i], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tt / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);

    return 0;
}

