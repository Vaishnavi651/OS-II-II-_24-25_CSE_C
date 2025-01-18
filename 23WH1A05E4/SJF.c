#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], at[20]; 
    int i, j, n, total = 0, totalT = 0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &at[i]); 
        p[i] = i + 1; 
    }

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on arrival time
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[pos]) {
                pos = j;
            }
        }

        // Swap burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap arrival times
        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;

        // Swap process numbers
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; // Waiting time for the first process is 0

    // Finding the waiting time of all the processes
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        
        // Calculate individual waiting time considering arrival times
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        
        // If the current process arrives after the previous one finishes,
        // adjust the waiting time accordingly.
        if (at[i] > wt[i]) {
            wt[i] = at[i]; // Set waiting time to arrival time if it arrives later
        } else {
            wt[i] -= at[i]; // Otherwise subtract its arrival time from total waiting time
        }

        total += wt[i]; // Total waiting time
    }

    // Calculate turnaround time and total turnaround time
    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time");
    
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; 
        totalT += tat[i]; // Total turnaround time

        printf("\np%d\t\t %d\t\t %d\t\t %d\t\t\t %d", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt = (float)total / n; 
    avg_tat = (float)totalT / n; 

    printf("\n\nAverage Waiting Time = %f", avg_wt);
    printf("\nAverage Turnaround Time = %f\n", avg_tat);

    return 0;
}
