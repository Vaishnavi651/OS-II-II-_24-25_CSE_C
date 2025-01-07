#include <stdio.h>
void bubblesort(int n, int process[], int arrival[], int brust[], int priority[]);
void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int process[n], arrival[n], brust[n], priority[n];    
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
    printf("Enter priorities (lower number indicates higher priority): ");
    for (int l = 0; l < n; l++) {
        scanf("%d", &priority[l]);
    }
    bubblesort(n, process, arrival, brust, priority);
    int ct[n]; 
    ct[0] = arrival[0] + brust[0];
    for (int m = 1; m < n; m++) {
        if (arrival[m] > ct[m - 1]) {
            ct[m] = arrival[m] + brust[m];
        } else {
            ct[m] = ct[m - 1] + brust[m];
        }
    }
    int tt[n], wt[n]; 
    for (int l = 0; l < n; l++) {
        tt[l] = ct[l] - arrival[l];
        wt[l] = tt[l] - brust[l];
    }
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], brust[i], priority[i], ct[i], tt[i], wt[i]);
    }
}
void bubblesort(int n, int process[], int arrival[], int brust[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arrival[j] > arrival[j + 1] || (arrival[j] == arrival[j + 1] && priority[j] > priority[j + 1])) {
                int temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp
			;
                int temp2 = brust[j];
                brust[j] = brust[j + 1];
                brust[j + 1] = temp2;

                int temp3 = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp3;

                int temp4 = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp4;
            }
        }
    }
}

















