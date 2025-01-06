#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processID[n], burstTime[n], arrivalTime[n];
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        processID[i] = i + 1; 
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burstTime[j] > burstTime[j + 1] ||
                (burstTime[j] == burstTime[j + 1] && arrivalTime[j] > arrivalTime[j + 1])) {
                int temp = processID[j];
                processID[j] = processID[j + 1];
                processID[j + 1] = temp;

                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;

                temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;
            }
        }
    }

    int completionTime = 0;

    for (int i = 0; i < n; i++) {
        if (completionTime > arrivalTime[i]) {
            waitingTime[i] = completionTime - arrivalTime[i];
        } else {
            waitingTime[i] = 0; 
        }

        turnaroundTime[i] = waitingTime[i] + burstTime[i];

        completionTime += burstTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    float avgWaitingTime = (float)totalWaitingTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nProcess  Burst Time  Arrival Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%-8d%-12d%-14d%-14d%-16d\n", processID[i], burstTime[i], arrivalTime[i], waitingTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
