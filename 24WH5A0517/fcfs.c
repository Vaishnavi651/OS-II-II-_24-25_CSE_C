#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // The waiting time for the first process is 0
   
  
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTime(int n, int bt[]) {
    int wt[n], tat[n];
   
   
    findWaitingTime(n, bt, wt);
   
   
    findTurnAroundTime(n, bt, wt, tat);
   
    
    int total_wt = 0, total_tat = 0;
   
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
   
  
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
   
   
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
   
   
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
}

int main() {
    int n;
   
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
   
    int burst_time[n];
   
   
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
   
  
    calculateAverageTime(n, burst_time);
   
    return 0;
}
