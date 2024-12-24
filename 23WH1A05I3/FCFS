#include<stdio.h>
int main() {
    int p[100], at[100], bt[100], n, ct[100], tat[100], wt[100], i, j, temp;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the process IDs: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the arrival times of each process: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter the burst times of each process: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j + 1]) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        temp = 0;
        if(ct[i - 1] < at[i]) {
            temp = at[i] - ct[i - 1];
        }
        ct[i] = ct[i - 1] + bt[i] + temp;
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nProcess  AT      BT      CT      TAT     WT");
    for(i = 0; i < n; i++) {
        printf("\nP%-8d%-8d%-8d%-8d%-8d%-8d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\n\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);

    return 0;
}
