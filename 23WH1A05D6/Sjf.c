#include <stdio.h>
int main() {
    int burst_time[20], p[20], waiting_time[20], tat[20];
    int n, i, j, total = 0, pos, temp;
    float avg_waiting_time, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the Burst Times:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        p[i] = i + 1; 
    }
    for (i = 0; i < n - 1; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (burst_time[j] < burst_time[pos]) {
                pos = j;
            }
      }
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        total += waiting_time[i];
    }
    avg_waiting_time = (float)total / n;
    total = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = burst_time[i] + waiting_time[i];
        total += tat[i];
        printf("p%d\t\t%d\t\t%d\t\t%d\n", p[i], burst_time[i], waiting_time[i], tat[i]);
    }
    avg_tat = (float)total / n;
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    return 0;
}

