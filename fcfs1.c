#include<stdio.h>
#include<stdlib.h>

void bubblesort(int n, int process[], int arrival[], int brust[]);

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n];
    int process[n];
    int brust[n];

    for(int j = 0; j < n; j++) {
        process[j] = j + 1;
    }

    printf("Enter arrival times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }

    printf("Enter burst times: ");
    for(int k = 0; k < n; k++) {
        scanf("%d", &brust[k]);
    }

    bubblesort(n, process, arrival, brust);

    int ct[n], tt[n], wt[n];
    int total_time = 0;

    for(int m = 0; m < n; m++) {
        if(total_time < arrival[m]) {
            total_time = arrival[m];
        }
        ct[m] = total_time + brust[m];
        total_time = ct[m];
    }

    for(int l = 0; l < n; l++) {
        tt[l] = ct[l] - arrival[l];
        wt[l] = tt[l] - brust[l];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], brust[i], ct[i], tt[i], wt[i]);
    }
}

void bubblesort(int n, int process[], int arrival[], int brust[]) {
    for(int a = 0; a < n - 1; a++) {
        for(int b = 0; b < n - 1 - a; b++) {
            if(arrival[b] > arrival[b + 1]) {
                int temp;

                temp = arrival[b];
                arrival[b] = arrival[b + 1];
                arrival[b + 1] = temp;

                temp = process[b];
                process[b] = process[b + 1];
                process[b + 1] = temp;

                temp = brust[b];
                brust[b] = brust[b + 1];
                brust[b + 1] = temp;
            }
        }
    }
}

