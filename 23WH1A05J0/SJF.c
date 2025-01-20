#include <stdio.h>

void sortProcesses(int n, int arrivetime[], int brusttime[], int process[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
           
            if (brusttime[i] > brusttime[j] || (brusttime[i] == brusttime[j] && arrivetime[i] > arrivetime[j])) {
               
                int temp = brusttime[i];
                brusttime[i] = brusttime[j];
                brusttime[j] = temp;
           
                temp = arrivetime[i];
                arrivetime[i] = arrivetime[j];
                arrivetime[j] = temp;
               
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
}

void displayTimes(int n, int arrivetime[], int brusttime[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Arrive time: %d  ", arrivetime[i]);
        printf("Burst time: %d \n", brusttime[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivetime[n], brusttime[n], process[n];
    int i;
    int waitingtime[n], turnaroundtime[n], completiontime[n];

   
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &arrivetime[i]);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &brusttime[i]);
    }

   
    sortProcesses(n, arrivetime, brusttime, process);

    displayTimes(n, arrivetime, brusttime);

    int time = 0;
    for (i = 0; i < n; i++) {
       
        if (time < arrivetime[i]) {
            time = arrivetime[i];
        }
        completiontime[i] = time + brusttime[i];  
        time = completiontime[i];  
       
    }

   
    for (i = 0; i < n; i++) {
        waitingtime[i] = completiontime[i] - arrivetime[i] - brusttime[i];
        turnaroundtime[i] = brusttime[i] + waitingtime[i]; //
    }

   
    printf("\nWaiting Time and Turnaround Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", process[i], waitingtime[i], turnaroundtime[i]);
    }

    return 0;
}
