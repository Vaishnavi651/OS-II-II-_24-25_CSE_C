#include <stdio.h>

void sortProcessesByBurstTime(int processes[], int burst_time[], int arrival_time[], int n) {
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

                
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n], arrival_time[n], waiting_time[n], turn_around_time[n];


    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    sortProcessesByBurstTime(processes, burst_time, arrival_time, n);
    int total_waiting_time = 0, total_turn_around_time = 0;
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }

        waiting_time[i] = current_time - arrival_time[i];
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }

        turn_around_time[i] = waiting_time[i] + burst_time[i];
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];

        current_time += burst_time[i];
    }

    
    printf("\nProcesses \t Burst Time \t Arrival Time \t Waiting Time \t Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n",
               processes[i], burst_time[i], arrival_time[i], waiting_time[i], turn_around_time[i]);
    }

    
    float average_waiting_time = (float)total_waiting_time / n;
    float average_turn_around_time = (float)total_turn_around_time / n;

    printf("\nAverage waiting time = %.2f\n", average_waiting_time);
    printf("Average turn-around time = %.2f\n", average_turn_around_time);

    return 0;
}

