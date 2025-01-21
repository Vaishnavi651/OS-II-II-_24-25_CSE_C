#include <stdio.h>
#include <stdlib.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int completed[n];
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    int t = 0;
    for (int count = 0; count < n; count++) {
        int min_index = -1;
        int min_burst = 9999;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && bt[j] < min_burst) {
                min_burst = bt[j];
                min_index = j;
            }
        }
        if (min_index != -1) {
            completed[min_index] = 1;
            wt[min_index] = t;
            t += bt[min_index];
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n];
    int burst_time[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", processes[i]);
        scanf("%d", &burst_time[i]);
    }
    findavgTime(processes, n, burst_time);
    return 0;
}
