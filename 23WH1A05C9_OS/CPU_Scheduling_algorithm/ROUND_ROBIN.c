//ROUND ROBIN

#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int remaining_bt[n];
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i]; // Initialize remaining burst times
    }

    int t = 0; // Current time

    // Loop to process all processes in a round-robin manner
    while (1) {
        int done = 1; // Assume all processes are done

        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) { // Check if the process still has burst time left
                done = 0; // There are pending processes

                if (remaining_bt[i] > quantum) {
                    // Process runs for 'quantum' time
                    t += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    // Process completes in the remaining time
                    t += remaining_bt[i];
                    wt[i] = t - bt[i];
                    remaining_bt[i] = 0; // Process is done
                }
            }
        }

        if (done == 1) {
            break; // Exit the loop when all processes are done
        }
    }
}

// Function to calculate turn-around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turn-around time = Burst time + Waiting time
    }
}

// Function to calculate average waiting and turn-around times
void findAvgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Calculate waiting time and turn-around time
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display results
    printf("Processes\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Display averages
    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turn-around time = %.2f\n", (float)total_tat / n);
}

// Main function
int main() {
    int n, quantum;

    // Input number of processes and time quantum
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int processes[n], burst_time[n];

    // Input burst times for each process
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Calculate and display average times
    findAvgTime(processes, n, burst_time, quantum);

    return 0;
}
