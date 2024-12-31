//fcfs
#include <stdio.h>

void sort(int pro[], int ari[], int bru[], int n) {
    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Process: %d, Arrival Time: %d, Burst Time: %d\n", pro[i], ari[i], bru[i]);
    }

    // Sorting based on arrival time (Bubble Sort)
    for (int a = 0; a < n - 1; a++) {
        for (int b = a + 1; b < n; b++) {  // Change the inner loop to avoid redundant comparisons
            if (ari[b] < ari[a]) {
                // Swap arrival times
                int temp = ari[b];
                ari[b] = ari[a];
                ari[a] = temp;

                // Swap burst times
                temp = bru[b];
                bru[b] = bru[a];
                bru[a] = temp;

                // Swap process IDs
                temp = pro[b];
                pro[b] = pro[a];
                pro[a] = temp;
            }
        }
    }

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Process: %d, Arrival Time: %d, Burst Time: %d\n", pro[i], ari[i], bru[i]);
    }
}

void avg(int pro[], int ari[], int bru[], int n) {
    int completion[n], turnaround[n], waiting[n];
    float avg_turnaround = 0, avg_waiting = 0;
    int time = 0;  // Time keeps track of the current time when the CPU is free

    // Calculate completion time, turnaround time, and waiting time for each process
    for (int i = 0; i < n; i++) {
        // If the process arrives after the current time, the CPU will idle until that time
        if (ari[i] > time) {
            time = ari[i];
        }

        // Completion time is the current time + burst time of the process
        completion[i] = time + bru[i];

        // Turnaround time = Completion time - Arrival time
        turnaround[i] = completion[i] - ari[i];

        // Waiting time = Turnaround time - Burst time
        waiting[i] = turnaround[i] - bru[i];

        // Update the current time for the next process
        time = completion[i];

        // Accumulate the average turnaround and waiting times
        avg_turnaround += turnaround[i];
        avg_waiting += waiting[i];
    }

    // Calculate averages
    avg_turnaround /= n;
    avg_waiting /= n;

    // Output the average times with 2 decimal places
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);
    printf("Average Waiting Time: %.2f\n", avg_waiting);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of processes must be greater than zero.\n");
        return 0;
    }

    int pro[n], ari[n], bru[n];

    printf("Enter the process IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pro[i]);
    }

    printf("Enter the arrival times:\n");
    for (int j = 0; j < n; j++) {
        scanf("%d", &ari[j]);
    }

    printf("Enter the burst times:\n");
    for (int k = 0; k < n; k++) {
        scanf("%d", &bru[k]);
    }

    // Input validation
    for (int i = 0; i < n; i++) {
        if (pro[i] < 0 || ari[i] < 0 || bru[i] < 0) {
            printf("Invalid input: process ID, arrival time, and burst time must be non-negative.\n");
            return 0;
        }
    }

    // Sorting based on arrival times
    sort(pro, ari, bru, n);

    // Calculate and print the average turnaround and waiting times
    printf("Average turnaround time and waiting time:\n");
    avg(pro, ari, bru, n);

    return 0;
}
