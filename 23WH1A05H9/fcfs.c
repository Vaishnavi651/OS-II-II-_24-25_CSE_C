#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], waiting[n], turnaround[n], processID[n];
    int totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        processID[i] = i + 1; 
        printf("\nEnter details for Process %d\n", processID[i]);
        printf("Enter Arrival Time: ");
        scanf("%d", &arrival[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &burst[i]);
    }

    // Sort processes by arrival time (using bubble sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival[i] > arrival[j]) {
                int tempArrival = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = tempArrival;

                int tempBurst = burst[i];
                burst[i] = burst[j];
                burst[j] = tempBurst;

                int tempID = processID[i];
                processID[i] = processID[j];
                processID[j] = tempID;
            }
        }
    }

    waiting[0] = 0; 
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }

    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processID[i], arrival[i], burst[i], waiting[i], turnaround[i]);
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }
    float avgWaiting = (float)totalWaiting / n;
    float avgTurnaround = (float)totalTurnaround / n;

    printf("\nAverage Waiting Time: %.2f", avgWaiting);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaround);

    return 0;
}
