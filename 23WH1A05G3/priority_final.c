#include <stdio.h>

void calculateWaitTime(int count, int arrival[], int burst[], int wait[]) {
    int currentTime = 0;
    for (int idx = 0; idx < count; idx++) {
        if (currentTime < arrival[idx]) {
            currentTime = arrival[idx];
        }
        wait[idx] = currentTime - arrival[idx];
        if (wait[idx] < 0) {
            wait[idx] = 0;
        }
        currentTime += burst[idx];
    }
}

void calculateTurnaroundTime(int count, int burst[], int wait[], int turnaround[]) {
    for (int idx = 0; idx < count; idx++) {
        turnaround[idx] = wait[idx] + burst[idx];
    }
}

void sortProcesses(int count, int proc[], int arrival[], int burst[], int priority[]) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (priority[i] > priority[j] || (priority[i] == priority[j] && arrival[i] > arrival[j])) {
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void displayResults(int count, int proc[], int arrival[], int burst[], int priority[], int wait[], int turnaround[]) {
    printf("\nProcess\tArrival Time\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int idx = 0; idx < count; idx++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[idx], arrival[idx], priority[idx], burst[idx], wait[idx], turnaround[idx]);
    }
}

void displayAverages(int count, int wait[], int turnaround[]) {
    double totalWait = 0, totalTurnaround = 0;
    for (int idx = 0; idx < count; idx++) {
        totalWait += wait[idx];
        totalTurnaround += turnaround[idx];
    }
    printf("\nAverage Waiting Time: %.2lf\n", totalWait / count);
    printf("Average Turnaround Time: %.2lf\n", totalTurnaround / count);
}

int main() {
    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    int processIDs[numProcesses], arrivalTimes[numProcesses], burstTimes[numProcesses], priorities[numProcesses];
    int waitingTimes[numProcesses], turnaroundTimes[numProcesses];

    for (int idx = 0; idx < numProcesses; idx++) {
        processIDs[idx] = idx + 1;
        printf("Enter arrival time for process P%d: ", processIDs[idx]);
        scanf("%d", &arrivalTimes[idx]);
        printf("Enter burst time for process P%d: ", processIDs[idx]);
        scanf("%d", &burstTimes[idx]);
        printf("Enter priority for process P%d: ", processIDs[idx]);
        scanf("%d", &priorities[idx]);
    }

    sortProcesses(numProcesses, processIDs, arrivalTimes, burstTimes, priorities);
    calculateWaitTime(numProcesses, arrivalTimes, burstTimes, waitingTimes);
    calculateTurnaroundTime(numProcesses, burstTimes, waitingTimes, turnaroundTimes);

    displayResults(numProcesses, processIDs, arrivalTimes, burstTimes, priorities, waitingTimes, turnaroundTimes);
    displayAverages(numProcesses, waitingTimes, turnaroundTimes);

    return 0;
}
