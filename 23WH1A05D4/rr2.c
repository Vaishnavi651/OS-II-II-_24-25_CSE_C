#include <stdio.h>

int main() {
    int n, time_quantum, total_time = 0, i, j, count = 0;
    int burst_time[10], waiting_time[10], turn_around_time[10], temp_burst_time[10]; 

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i]; 
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    for (total_time = 0, i = 0; count != n; ) {
        if (temp_burst_time[i] <= time_quantum && temp_burst_time[i] > 0) {
            total_time += temp_burst_time[i];
            temp_burst_time[i] = 0;
            count++;
        } else if (temp_burst_time[i] > 0) {
            total_time += time_quantum;
            temp_burst_time[i] -= time_quantum;
        }

        if (temp_burst_time[i] == 0 && count != n) {
            waiting_time[i] = total_time - burst_time[i];
            turn_around_time[i] = total_time;
            i = (i + 1) % n; 
        }
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    return 0;
}
