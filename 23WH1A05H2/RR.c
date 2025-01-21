#include <stdio.h>

int main() {
    int n, quantum, i, count = 0, time = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int burst_time[n], temp_burst_time[n], waiting_time[n], turnaround_time[n];
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (temp_burst_time[i] > 0) {
                done = 0;
                if (temp_burst_time[i] > quantum) {
                    time += quantum;
                    temp_burst_time[i] -= quantum;
                } else {
                    time += temp_burst_time[i];
                    waiting_time[i] = time - burst_time[i];
                    temp_burst_time[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
    
    printf("\nProcesses    Burst Time    Waiting Time    Turn-Around Time\n");
    for (i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        printf("%d           %d             %d                %d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    
    printf("Average waiting time = %.2f\n", avg_waiting_time / n);
    printf("Average turn-around time = %.2f\n", avg_turnaround_time / n);
    return 0;
}
