#include <stdio.h>

void bubblesort(int n, int process[], int arrival[], int burst[]);

void main() {
    int n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], process[n], arrival[n], rem_burst[n];
    for (int i = 0; i < n; i++) {
        process[i] = i + 1;
    }

    for(int i=0;i<n;i++) {
        printf("Arrival time of Process %d: ", process[i]);
        scanf("%d", &arrival[i]);
        printf("Burst time of Process %d: ", process[i]);
        scanf("%d", &burst[i]);
    }

    for (int i = 0; i < n; i++) {
        rem_burst[i] = burst[i];
    }

    printf("Give time quantum: ");
    scanf("%d", &tq);

    bubblesort(n, process, arrival, burst);

    int ct[n], tt[n], wt[n], completed = 0;
    int current_time = 0;
    int queue[100], front = 0, rear = 0;
    int in_queue[n];

    for (int i = 0; i < n; i++) {
        in_queue[i] = 0;
    }

    queue[rear++] = 0;
    in_queue[0] = 1;

    while (completed != n) {
        int i = queue[front++];
        if (front == 100) front = 0; 

        if (rem_burst[i] > 0) {
            if (rem_burst[i] > tq) {
                current_time += tq;
                rem_burst[i] -= tq;
            } else {
                current_time += rem_burst[i];
                rem_burst[i] = 0;
                ct[i] = current_time;
                completed++;
            }

            for (int j = 0; j < n; j++) {
                if (j != i && arrival[j] <= current_time && rem_burst[j] > 0 && in_queue[j] == 0) {
                    queue[rear++] = j;
                    if (rear == 100) rear = 0;
                    in_queue[j] = 1;
                }
            }

            if (rem_burst[i] > 0) {
                queue[rear++] = i;
                if (rear == 100) rear = 0; 
            }
        }

        if (front == rear) {
            for (int j = 0; j < n; j++) {
                if (rem_burst[j] > 0) {
                    current_time = arrival[j];
                    queue[rear++] = j;
                    if (rear == 100) rear = 0; 
                    in_queue[j] = 1;
                    break;
                }
            }
        }
    }

    float total_tt = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        tt[i] = ct[i] - arrival[i];
        wt[i] = tt[i] - burst[i];
        total_tt += tt[i];
        total_wt += wt[i];
    }

    float avg_tt = total_tt / n;
    float avg_wt = total_wt / n;

    printf("\nProcess\tArrival\tBurst\tTurnaround\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], tt[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}

void bubblesort(int n, int process[], int arrival[], int burst[]) {
    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - 1 - a; b++) {
            if (arrival[b] > arrival[b + 1]) {
                int temp;

                temp = arrival[b];
                arrival[b] = arrival[b + 1];
                arrival[b + 1] = temp;

                temp = process[b];
                process[b] = process[b + 1];
                process[b + 1] = temp;

                temp = burst[b];
                burst[b] = burst[b + 1];
                burst[b + 1] = temp;
            }
        }
    }
}
