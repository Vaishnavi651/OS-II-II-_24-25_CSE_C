#include <stdio.h>
#include <stdlib.h>

void sort(int n, int p[100], int at[100], int bt[100]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (bt[i] > bt[j]) { 

                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes to analyze: ");
    scanf("%d", &n);
    
    int bt[100], at[100], tt[100], ct[100], wt[100], p[100];

    printf("Enter the arrival time and burst time of processes:\n");
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        scanf("%d %d", &at[i], &bt[i]);
    }

    sort(n, p, at, bt);

    int sum = 0, sum1 = 0, sum2 = 0;

    for (int x = 0; x < n; x++) {
        sum += bt[x];
        ct[x] = sum;  
    }

    for (int c = 0; c < n; c++) {
        tt[c] = ct[c] - at[c];
    }

    for (int g = 0; g < n; g++) {
        wt[g] = tt[g] - bt[g];
    }

    for (int y = 0; y < n; y++) {
        sum1 += tt[y];
        sum2 += wt[y];
    }

    printf("Processes    Arrival Time    Burst Time    Completion Time    Turnaround Time    Waiting Time\n");
    for (int x = 0; x < n; x++) {
        printf("%d           %d              %d              %d                %d               %d\n",
               p[x], at[x], bt[x], ct[x], tt[x], wt[x]);
    }

    printf("The average Turnaround Time is: %.2f\n", (float)sum1 / n);
    printf("The average Waiting Time is: %.2f\n", (float)sum2 / n);

    return 0;
}

