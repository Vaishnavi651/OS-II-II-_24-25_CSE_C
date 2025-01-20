#include <stdio.h>

int main() {
    int p[100], at[100], bt[100], pr[100], n, ct[100], tat[100], wt[100], i, j, temp;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    printf("Enter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

   
    printf("Enter the arrival times of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

   
    printf("Enter the burst times of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Enter the priorities of each process: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pr[j] > pr[j + 1] || (pr[j] == pr[j + 1] && at[j] > at[j + 1])) {
               
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
               
                temp = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = temp;
               
            }
        }
    }


   
    int currentTime = 0;
    for (i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i];
        }
        currentTime += bt[i];
        ct[i] = currentTime;
    }
   
   

   
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
    }

 
    wt[0]=0;
    for (i = 1; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }

    printf("\nProcess  AT      BT    Priority   CT      TAT     WT");
    for (i = 0; i < n; i++) {
        printf("\nP%-8d%-8d%-8d%-8d%-8d%-8d%-8d", p[i], at[i], bt[i],pr[i], ct[i], tat[i], wt[i]);
    }

   
    for (i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;
    printf("\n\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);

    return 0;
}

