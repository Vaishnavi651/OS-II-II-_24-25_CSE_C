#include <stdio.h>

void calculate(int n, int bt[], int at[], int wt[], int tat[]) {
    int twt = 0, ttat = 0;

    wt[0] = 0;

    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1] - at[i];
        if (wt[i] < 0) wt[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\nProcesses\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (int i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)twt / n);
    printf("\nAverage turn-around time = %.2f\n", (float)ttat / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &at[i]);
    }

    calculate(n, bt, at, wt, tat);

    return 0;
}
