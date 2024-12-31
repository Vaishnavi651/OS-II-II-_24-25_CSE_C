#include <stdio.h>

int main() {
    int n, bt[30], at[30], wait_t[30], turn_ar_t[30], i, j;
    float av_wt_t = 0, avturn_ar_t = 0;

    printf("Enter the total number of processes:");
    scanf("%d", &n);

    printf("\nEnter The Process Burst Time and Arrival Time:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]:\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
    }

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival times
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    wait_t[0] = 0;

    for (i = 1; i < n; i++) {
        wait_t[i] = 0;
        for (j = 0; j < i; j++) {
            wait_t[i] += bt[j];
        }
        wait_t[i]-=at[i];
        if(wait_t[i]<0) wait_t[i]=0;
    }

    printf("\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++) {
        turn_ar_t[i] = bt[i] + wait_t[i];
        av_wt_t += wait_t[i];
        avturn_ar_t += turn_ar_t[i];
        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d", i + 1, bt[i],at[i], wait_t[i], turn_ar_t[i]);
    }

    av_wt_t /= n;
    avturn_ar_t /= n;
    printf("\nAverage Waiting Time:%.2f", av_wt_t);
    printf("\nAverage Turnaround Time:%.2f", avturn_ar_t);

    return 0;
}
