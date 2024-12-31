#include <stdio.h>

// Function declarations
void tur(int n, int ct[n], int at[n], int tt[n]);
void swap(int n, int p[n], int at[n], int bt[n]);
void com(int n, int bt[n], int at[n], int ct[n]);
void wai(int n, int tt[n], int bt[n], int wt[n]);

int main() {
    int n, i, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], ct[n], tt[n], wt[n]; 
    for(i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // Input the arrival times
    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    // Input the burst times
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    // Sort processes based on arrival times and burst times
    swap(n, p, at, bt);

    // Calculate completion times
    com(n, bt, at, ct);
    
    tur(n, ct, at, tt);

    wai(n, tt, bt, wt);

    // Output the details (Process ID, Arrival Time, Burst Time, Completion Time, TT, WT)
    int sum_tt = 0, sum_wt = 0;
    printf("\nPID\t\tAT\t\tBT\t\tCT\t\tTT\t\tWT\n");
    for(k = 0; k < n; k++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[k], at[k], bt[k], ct[k], tt[k], wt[k]);
    
        sum_tt += tt[k];
        sum_wt += wt[k];
    }

    int avg_tt = sum_tt / n;
    int avg_wt = sum_wt / n;
    printf("Average turnaround time is : %d\n", avg_tt);
    printf("Average waiting time is : %d", avg_wt);
       
    return 0;
}

// Function to swap processes based on arrival time (sorting)
void swap(int n, int p[n], int at[n], int bt[n]) {
    int j, k, temp;
    for(j = 0; j < n - 1; j++) {
        for(k = j + 1; k < n; k++) {
            if(at[j] > at[k] || (at[j] == at[k] && bt[j] > bt[k])) {
                // Swap arrival times
                temp = at[j];
                at[j] = at[k];
                at[k] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[k];
                bt[k] = temp;

                // Swap process IDs
                temp = p[j];
                p[j] = p[k];
                p[k] = temp;
            }
        }
    }
}

// Function to calculate completion times
void com(int n, int bt[n], int at[n], int ct[n]) {
    int sum = 0, i;

    for(i = 0; i < n; i++) {
        if(i == 0 || at[i] > sum) {
            sum = at[i];  // If a process arrives later than the previous one, start at its arrival time
        }
        sum += bt[i];  // Accumulate burst times to get completion times
        ct[i] = sum;   // Set the completion time for process i
    }
}

// Function to calculate turnaround times
void tur(int n, int ct[n], int at[n], int tt[n]) {
    int i;
    for(i = 0; i < n; i++) {
        tt[i] = ct[i] - at[i];  // Turnaround time = Completion time - Arrival time
    }
}

// Function to calculate waiting times
void wai(int n, int tt[n], int bt[n], int wt[n]) {
    int i;
    for(i = 0; i < n; i++) {
        wt[i] = tt[i] - bt[i];  // Waiting time = Turnaround time - Burst time
    }
}

