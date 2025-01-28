#include<stdio.h>
int main(){
        int A[100][5]; // Adding one more column for Arrival Time
        int i, j, n, total=0, temp, index, time = 0, completed = 0;
        float avg_wt, avg_tat;

        printf("Enter number of processes: ");
        scanf("%d", &n);

        printf("Enter Arrival Time and Burst Time:\n");
        for (i = 0; i < n; i++) {
                printf("P%d Arrival Time: ", i + 1);
                scanf("%d", &A[i][1]); // Arrival Time
                printf("P%d Burst Time: ", i + 1);
                scanf("%d", &A[i][2]); // Burst Time
                A[i][0] = i + 1;       // Process ID
        }

        // Sort by Arrival Time first, then Burst Time if Arrival Times are the same
        for (i = 0; i < n; i++) {
                index = i;
                for (j = i + 1; j < n; j++) {
                        if (A[j][1] < A[index][1] ||
                           (A[j][1] == A[index][1] && A[j][2] < A[index][2])) {
                                index = j;
                        }
                }
                // Swap Arrival Time, Burst Time, and Process ID
                for (int k = 0; k < 3; k++) {
                        temp = A[i][k];
                        A[i][k] = A[index][k];
                        A[index][k] = temp;
                }
        }

        int WT[100] = {0}, TAT[100] = {0}, isCompleted[100] = {0};
        while (completed < n) {
                int minIndex = -1, minBT = 10000;

                // Find the process with the shortest burst time among arrived processes
                for (i = 0; i < n; i++) {
                        if (A[i][1] <= time && !isCompleted[i] && A[i][2] < minBT) {
                                minBT = A[i][2];
                                minIndex = i;
                        }
                }

                if (minIndex == -1) {
                        // If no process has arrived, increment the time
                        time++;
                        continue;
                }

                // Execute the process
                time += A[minIndex][2];
                WT[minIndex] = time - A[minIndex][1] - A[minIndex][2];
                TAT[minIndex] = time - A[minIndex][1];
                total += WT[minIndex]; // Add Waiting Time to Total
                completed++;
                isCompleted[minIndex] = 1;
        }

        // Calculate Average Times
        avg_wt = total / (float)n;
        total = 0;
        for (i = 0; i < n; i++) {
                total += TAT[i];
        }
        avg_tat = total / (float)n;

        // Display Results
        printf("P     AT     BT     WT     TAT\n");
        for (i = 0; i < n; i++) {
                printf("P%d    %d     %d     %d     %d\n", A[i][0], A[i][1], A[i][2], WT[i], TAT[i]);
        }
        printf("Average Waiting Time = %f\n", avg_wt);
        printf("Average Turnaround Time = %f\n", avg_tat);

        return 0;
}
