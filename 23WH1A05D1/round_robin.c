#include <stdio.h>

int main() {
    int count, j, n, time = 0, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int arrival_time[10], burst_time[10], remaining_time[10];

    // Input validation for total processes
    printf("Enter Total Processes (max 10): ");
    scanf("%d", &n);

    remain = n;

    // Input process details with validation
    for (count = 0; count < n; count++) {
        printf("Enter Arrival Time and Burst Time for Process Number %d: ", count + 1);
        scanf("%d", &arrival_time[count]);
        scanf("%d", &burst_time[count]);

        remaining_time[count] = burst_time[count];
    }

    // Input and validate time quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &time_quantum);
  

    printf("\nProcess\t|Turnaround Time|Waiting Time\n");
    printf("----------------------------------------\n");

    // Main scheduling loop
    for (time = 0, count = 0; remain != 0;) {
        if (remaining_time[count] <= time_quantum && remaining_time[count] > 0) {
            time += remaining_time[count];
            remaining_time[count] = 0;
            flag = 1;
        }
        else if (remaining_time[count] > 0) {
            remaining_time[count] -= time_quantum;
            time += time_quantum;
        }

        if (remaining_time[count] == 0 && flag == 1) {
            remain--;
            int process_tat = time - arrival_time[count];
            int process_wt = process_tat - burst_time[count];

            printf("P[%d]\t|\t%d\t|\t%d\n",
                   count + 1, process_tat, process_wt);

            wait_time += process_wt;
            turnaround_time += process_tat;
            flag = 0;
        }

        // Move to next process
        if (count == n - 1)
            count = 0;
        else if (arrival_time[count + 1] <= time)
            count++;
        else
            count = 0;
    }

    // Calculate and display averages
    float avg_waiting_time = (float)wait_time / n;
    float avg_turnaround_time = (float)turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
