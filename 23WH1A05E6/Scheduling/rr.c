#include <stdio.h>

int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], n, i, j, temp, quantum;
    int rem_bt[10];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
   
    printf("Enter process numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
   
    printf("Enter arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
   
    printf("Enter burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
   
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
   
    int time = 0, count = 0;
    while (count < n) {
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    ct[i] = time;
                    rem_bt[i] = 0;
                    count++;
                }
            }
        }
    }
   
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
   
    atat = atat / n;
    awt = awt / n;
   
    printf("\np\tA.T\tB.T\tC.T\tT.A.T\tW.T\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
   
    printf("\nAverage Turnaround Time: %f", atat);
    printf("\nAverage Waiting Time: %f", awt);
   
    return 0;
}
