#include<stdio.h>

int main(){
    int A[100][3], i, j, n, total = 0, temp, index, time = 0, completed = 0;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &A[i][1]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &A[i][2]);
        A[i][0] = i + 1;
    }

    int WT[100] = {0}, TAT[100] = {0}, isCompleted[100] = {0};

    while (completed < n) {
        int minIndex = -1, minBT = 10000;

        for (i = 0; i < n; i++) {
            if (A[i][1] <= time && !isCompleted[i] && A[i][2] < minBT) {
                minBT = A[i][2];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            time++;
            continue;
        }

        time += A[minIndex][2];
        WT[minIndex] = time - A[minIndex][1] - A[minIndex][2];
        TAT[minIndex] = time - A[minIndex][1];
        total += WT[minIndex];
        completed++;
        isCompleted[minIndex] = 1;
    }

    avg_wt = total / (float)n;
    total = 0;
    for (i = 0; i < n; i++) {
        total += TAT[i];
    }
    avg_tat = total / (float)n;

    printf("P     AT     BT     WT     TAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d    %d     %d     %d     %d\n", A[i][0], A[i][1], A[i][2], WT[i], TAT[i]);
    }
    printf("Average Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);

    return 0;
}

