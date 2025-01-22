#include <stdio.h>
void roundRobin(int n, int process[], int arrival[], int brust[], int quantum);
int main() {
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int process[n], arrival[n], brust[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }
    
    printf("Enter arrival times: ");
    for (int j = 0; j < n; j++) {
        scanf("%d", &arrival[j]);
    }
    
    printf("Enter burst times: ");
    for (int k = 0; k < n; k++) {
        scanf("%d", &brust[k]);
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    roundRobin(n, process, arrival, brust, quantum);
    
    return 0;
}
void roundRobin(int n, int process[], int arrival[], int brust[], int quantum) {
    int ct[n]; 
    int tt[n]; 
    int wt[n]; 
    int remaining[n]; 
    int time = 0; 
    int completed = 0; 

    for (int i = 0; i < n; i++) {
        remaining[i] = brust[i];
    }

    while (completed < n) {
        int done = 0; 

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0) {
                done = 1; 

                if (remaining[i] > quantum) {
                    time += quantum; 
                    remaining[i] -= quantum; 
                } else {
                    time += remaining[i]; 
                    ct[i] = time; 
                    remaining[i] = 0; 
                    completed++; 
                }
            }
        }

        if (!done) {
            time++;
        }
    }

    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - arrival[i];
        wt[i] = tt[i] - brust[i];
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], brust[i], ct[i], tt[i], wt[i]);
    }
}