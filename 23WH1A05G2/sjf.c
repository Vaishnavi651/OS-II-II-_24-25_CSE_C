#include<stdio.h>

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], process[n];
    int ct[n], tt[n], wt[n], completed[n];
    
    for(int i = 0; i < n; i++) {
        process[i] = i + 1;
        completed[i] = 0; 
    }

    printf("Enter arrival times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }

    printf("Enter burst times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
    }

    int total_time = 0, completed_count = 0;

    while(completed_count < n) {
        int idx = -1;
        int min_burst = 1e9;

        for(int i = 0; i < n; i++) {
            if(arrival[i] <= total_time && completed[i] == 0) {
                if(burst[i] < min_burst) {
                    min_burst = burst[i];
                    idx = i;
                }
                else if(burst[i] == min_burst) {
                    if(arrival[i] < arrival[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            total_time += burst[idx];
            ct[idx] = total_time;
            completed[idx] = 1;
            completed_count++;
        } else {
            total_time++;
        }
    }

    for(int i = 0; i < n; i++) {
        tt[i] = ct[i] - arrival[i];
        wt[i] = tt[i] - burst[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], ct[i], tt[i], wt[i]);
    }
}
