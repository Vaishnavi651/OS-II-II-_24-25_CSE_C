#include <stdio.h>

int main()
{
    int A[100][5];
    int i, j, n, total = 0, index, temp;
    float avg_wt, avg_tat;
    
    printf("Enter number of process: ");
    scanf("%d", &n);
    
    printf("Enter Arrival Time and Burst Time:\n");
    
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &A[i][2]);
        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1;
    }
    
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++)
            if (A[j][2] < A[index][2])
                index = j;
        
        temp = A[i][2];
        A[i][2] = A[index][2];
        A[index][2] = temp;

        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;

        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    
    A[0][3] = 0;
    
    for (i = 1; i < n; i++) {
        A[i][3] = 0;
        for (j = 0; j < i; j++)
            A[i][3] += A[j][1];
        total += A[i][3];
    }
    
    avg_wt = (float)total / n;
    total = 0;
    
    printf("P  AT  BT  WT  TAT\n");
    
    for (i = 0; i < n; i++) {
        A[i][4] = A[i][1] + A[i][3];
        total += A[i][4];
        printf("P%d  %d  %d  %d  %d\n", A[i][0], A[i][2], A[i][1], A[i][3], A[i][4]);
    }
    
    avg_tat = (float)total / n;
    
    printf("Average Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);

    return 0;
}
