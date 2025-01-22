#include <stdio.h>
void findWaitingTime(int n, int bt[], int wt[], int priority[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
    }
}
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTime(int n, int bt[], int priority[]) {
    int wt[n], tat[n];
    findWaitingTime(n, bt, wt, priority);
    findTurnAroundTime(n, bt, wt, tat);
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], priority[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

void sortProcessesByPriority(int n, int bt[], int process[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], priority[n], process[n];
    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d - Burst Time: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Process %d - Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }
    sortProcessesByPriority(n, bt, process, priority);
    calculateAverageTime(n, bt, priority);

    return 0;
}
