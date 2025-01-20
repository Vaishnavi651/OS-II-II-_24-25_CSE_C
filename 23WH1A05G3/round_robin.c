#include<stdio.h>

void main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    int burst[n], arrival[n], process[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    printf("Give burst time for each process: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    printf("Give arrival time for each process: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }

    int wt[n], rt[n], current_t[n], ct[n], tt[n], total_time = 0;
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        rt[i] = burst[i];
        current_t[i] = 0;
    }

    int completed = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && arrival[i] <= total_time) {
                if (rt[i] > tq) {
                    total_time += tq;
                    rt[i] -= tq;
                } else {
                    total_time += rt[i];
                    ct[i] = total_time;
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - arrival[i];
        wt[i] = tt[i] - burst[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", process[i], burst[i], wt[i], tt[i]);
    }
}

