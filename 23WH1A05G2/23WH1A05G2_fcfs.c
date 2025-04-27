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

    for(int i= 0; i< n; i++) {
        process[i] = i+ 1;
    }

    printf("Enter arrival times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arrival[i]);
    }

    printf("Enter burst times: ");
    for(int i= 0; i< n; i++) {
        scanf("%d", &brust[i]);
    }

    bubblesort(n, process, arrival, brust);

    int ct[n], tt[n], wt[n];
    int total_time = 0;

    for(int i = 0; i < n; i++) {
        if(total_time < arrival[i]) {
            total_time = arrival[i];
        }
        ct[i] = total_time + brust[i];
        total_time = ct[i];
    }

    for(int i = 0; i < n; i++) {
        tt[i] = ct[i] - arrival[i];
        wt[i] = tt[i] - brust[i];
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

