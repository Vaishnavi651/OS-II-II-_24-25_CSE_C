#include <stdio.h>
void bubblesort(int at[], int bt[], int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int t1 = at[j], t2 = bt[j], t3 = arr[j];
                at[j] = at[j + 1];
                bt[j] = bt[j + 1];
                arr[j] = arr[j + 1];
                at[j + 1] = t1;
                bt[j + 1] = t2;
                arr[j + 1] = t3;
            }
        }
    }
}


void turnaround(int at[], int bt[], int n, int tat[], int comp[]) {
    comp[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (comp[i - 1] < at[i]) {
            comp[i] = at[i] + bt[i];
        } else {
            comp[i] = comp[i - 1] + bt[i];
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = comp[i] - at[i];
    }
}

void waiting(int tat[], int bt[], int n, int wait[]) {
    for (int i = 0; i < n; i++) {
        wait[i] = tat[i] - bt[i];
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arr[n], wait[n], tat[n], bt[n], at[n], comp[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    bubblesort(at, bt, arr, n);

    turnaround(at, bt, n, tat, comp);

    waiting(tat, bt, n, wait);

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", arr[i], at[i], bt[i], comp[i], tat[i], wait[i]);
    }

    float avg_tat = 0, avg_wait = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wait += wait[i];
    }
    printf("\nAverage Turnaround Time: %.2f", avg_tat / n);
    printf("\nAverage Waiting Time: %.2f\n", avg_wait / n);

    return 0;
}
