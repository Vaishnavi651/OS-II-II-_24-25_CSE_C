#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], at[10], pr[10], wt[10], tat[10], completed[10], process[10];
    float total_wt = 0, total_tat = 0;

    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &pr[i]);
        process[i] = i + 1; 
        completed[i] = 0;   
    }

   
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {
               
                int temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

               
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }

    
    int time = 0;

    
    for (i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i]; 
        }

        wt[i] = time - at[i]; 
        if (wt[i] < 0) {
            wt[i] = 0; 
        }

        time += bt[i]; 
        tat[i] = wt[i] + bt[i]; 

        total_wt += wt[i];
        total_tat += tat[i];
    }

   
    printf("\nProcesses\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], pr[i], at[i], bt[i], wt[i], tat[i]);
    }

   
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", total_tat / n);

    return 0;
}
