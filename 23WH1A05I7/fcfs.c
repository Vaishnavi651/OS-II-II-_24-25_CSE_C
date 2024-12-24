#include <stdio.h>

void sort(int a[], int p[], int b[], int n);
void calculateCompletionTime(int a[], int b[], int completionTime[], int n);
void calculateTurnaroundTime(int a[], int completionTime[], int turnaroundTime[], int n);
void calculateWaitingTime(int turnaroundTime[], int b[], int waitingTime[], int n);

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], a[n], b[n];
    int completionTime[n], turnaroundTime[n], waitingTime[n];

    printf("Enter the process IDs: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", p[i]);
        scanf("%d", &a[i]);
        printf("Enter the burst time of process %d: ", p[i]);
        scanf("%d", &b[i]);
    }

    sort(a, p, b, n);

    calculateCompletionTime(a, b, completionTime, n);
    calculateTurnaroundTime(a, completionTime, turnaroundTime, n);
    calculateWaitingTime(turnaroundTime, b, waitingTime, n);

    printf("\nProcessID ArrivalTime BurstTime CompletionTime TurnaroundTime WaitingTime\n");
    for (i = 0; i < n; i++) {
       printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n", p[i], a[i], b[i], completionTime[i], turnaroundTime[i], waitingTime[i]);
    }

    float totalTurnaroundTime = 0, totalWaitingTime = 0;
    for (i = 0; i < n; i++) {
        totalTurnaroundTime += turnaroundTime[i];
        totalWaitingTime += waitingTime[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);

    return 0;
}

void sort(int a[], int p[], int b[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap arrival times
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                // Swap burst times
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}

void calculateCompletionTime(int a[], int b[], int completionTime[], int n) {
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < a[i]) {
            currentTime = a[i];
        }
        currentTime += b[i];
        completionTime[i] = currentTime;
    }
}

void calculateTurnaroundTime(int a[], int completionTime[], int turnaroundTime[], int n) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - a[i];
    }
}

void calculateWaitingTime(int turnaroundTime[], int b[], int waitingTime[], int n) {
    for (int i = 0; i < n; i++) {
        waitingTime[i] = turnaroundTime[i] - b[i];
    }
}

