#include <stdio.h>

int main() {
    int n, i, qt, t = 0, completed = 0;
    int p[10], at[10], bt[10], rem_bt[10], ct[10], tat[10], wt[10];
    float total_tat = 0, total_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; 
    }

    printf("Enter the time quantum: ");
    scanf("%d", &qt);
    while (completed < n) {
        int idle = 1; 

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                idle = 0; 

                if (rem_bt[i] > qt) {
                    t += qt;        
                    rem_bt[i] -= qt;
                } else {
                    t += rem_bt[i];  
                    ct[i] = t;   
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i]; 
                    rem_bt[i] = 0; 
                    completed++;
                }
            }
        }
    if (idle) { 
            t++;
        }
    }
   
    for (i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\tCT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }

    printf("\n\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

return 0;
}
