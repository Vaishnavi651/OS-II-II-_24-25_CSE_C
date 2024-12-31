#include <stdio.h>

int main()
{
    int A[100][5]; 
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

   
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &A[i][1]);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &A[i][0]);
        A[i][4] = i + 1; 
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (A[i][0] > A[j][0] || (A[i][0] == A[j][0] && A[i][1] > A[j][1])) {
                temp = A[i][0];
                A[i][0] = A[j][0];
                A[j][0] = temp;
                temp = A[i][1];
                A[i][1] = A[j][1];
                A[j][1] = temp;
                temp = A[i][4];
                A[i][4] = A[j][4];
                A[j][4] = temp;
            }
        }
    }

    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < A[i][0]) {
            current_time = A[i][0]; 
        }
        A[i][2] = current_time - A[i][0]; 
        current_time += A[i][1]; 
        A[i][3] = A[i][2] + A[i][1];    
        total += A[i][2];
    }

    avg_wt = (float)total / n;
    total = 0;

    printf("\nProcesses  Burst Time  Waiting Time  Turn-Around Time\n");
    for (i = 0; i < n; i++) {
        total += A[i][3];
        printf("%d          %d           %d              %d\n", A[i][4], A[i][1], A[i][2], A[i][3]);
    }

    avg_tat = (float)total / n;
    printf("\nAverage waiting time = %.2f", avg_wt);
    printf("\nAverage turn-around time = %.2f\n", avg_tat);

    return 0;
}
