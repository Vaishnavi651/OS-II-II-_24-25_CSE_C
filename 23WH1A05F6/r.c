#include <stdio.h>
#include <stdlib.h>

float avg(int a[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

int main() {
    int n, time_quantum;
    printf("ENTER no of ELEMENT : ");
    scanf("%d", &n);
    int a[n]; // Arrival time
    int p[n]; // Process ID
    int bt[n]; // Burst time
    int rem_bt[n]; // Remaining burst time
    int c[n]; // Completion time
    int tt[n]; // Turnaround time
    int wt[n]; // Waiting time

    for (int i = 0; i < n; i++) {
        p[i] = i + 1; // Process IDs
    }

    printf("ENTER arrival time :\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("ENTER burst time :\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }
    printf("ENTER time quantum : ");
    scanf("%d", &time_quantum);

    int t = 0; // Current time
    int done;
    do {
        done = 1; // Assume all processes are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && a[i] <= t) { // Process is ready
                done = 0; // There is at least one process that is not done
                if (rem_bt[i] > time_quantum) {
                    t += time_quantum; // Increment time by time quantum
                    rem_bt[i] -= time_quantum; // Decrease remaining burst time
                } else {
                    t += rem_bt[i]; // Increment time by remaining burst time
                    c[i] = t; // Completion time
                    rem_bt[i] = 0; // Process is finished
                }
            }
        }
    } while (!done); // Repeat until all processes are done

    for (int i = 0; i < n; i++) {
        tt[i] = c[i] - a[i]; // Turnaround time
        wt[i] = tt[i] - bt[i]; // Waiting time
    }

    printf("\n%-8s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-8d%-15d%-15d%-15d%-15d\n", p[i], a[i], bt[i], tt[i], wt[i]);
    }

    printf("avg waiting time :%f\n", avg(wt, n));
    printf("avg turn around time :%f\n", avg(tt, n));

    return 0;
}
