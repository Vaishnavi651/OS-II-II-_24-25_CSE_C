#include <stdio.h>
void bubbleSort(int n, int arrival_time[], int burst_time[], int process[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1] ||
                (burst_time[j] == burst_time[j + 1] && arrival_time[j] > arrival_time[j + 1])) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp;

                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j + 1];
                arrival_time[j + 1] = temp;

                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n], process[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1; 
        printf("Process %d - Arrival Time: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    bubbleSort(n, arrival_time, burst_time, process);

    waiting_time[0] = 0; 
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1] - (arrival_time[i] - arrival_time[i - 1]);
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%-7d\t%-12d\t%-10d\t%-12d\t%-15d\n", process[i], arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}

