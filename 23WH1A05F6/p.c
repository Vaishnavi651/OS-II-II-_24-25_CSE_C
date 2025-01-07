#include <stdio.h>
#include <stdlib.h>

void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

float avg(int a[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

void prioritysort(int a[], int p[], int bt[], int pr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pr[j] < pr[i]) { 
                swap(&a[i], &a[j]);
                swap(&p[i], &p[j]);
                swap(&bt[i], &bt[j]);
                swap(&pr[i], &pr[j]);
            }
        }
    }
}

int main() {
    int n;
    printf("ENTER no of ELEMENT : ");
    scanf("%d", &n);
    int a[n]; 
    int p[n]; 
    int bt[n]; 
    int pr[n]; 

    for (int i = 0; i < n; i++) {
        p[i] = i + 1; 
    }

    printf("ENTER arrival time :\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("ENTER burst time :\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("ENTER priority (lower number means higher priority):\n ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pr[i]);
    }

    prioritysort(a, p, bt, pr, n);

    int c[n];
    c[0] = a[0] + bt[0];
    for (int i = 1; i < n; i++) {
        c[i] = bt[i] + c[i - 1];
    }
    int tt[n]; 
    for (int i = 0; i < n; i++) {
        tt[i] = c[i] - a[i];
    }
    int wt[n]; 
    for (int i = 0; i < n; i++) {
        wt[i] = tt[i] - bt[i];
    }

    printf("\n%-8s%-15s%-15s%-15s%-15s\n", "Process", "Arrival Time", "Burst Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-8d%-15d%-15d%-15d%-15d\n", p[i], a[i], bt[i], tt[i], wt[i]);
    }

    printf("avg waiting time :%f\n", avg(wt, n));
    printf("avg turn around time :%f\n", avg(tt, n));

    return 0;
}
