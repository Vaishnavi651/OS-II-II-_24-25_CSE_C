#include <stdio.h>

struct Process {
    int id;         
    int arrival;    
    int burst;      
    int waiting;    
    int turnaround; 
};

void findWaitingTime(struct Process proc[], int n) {
    proc[0].waiting = 0; 
        for (int i = 1; i < n; i++) {
        proc[i].waiting = proc[i - 1].waiting + proc[i - 1].burst;
               if (proc[i].waiting < proc[i].arrival) {
            proc[i].waiting = proc[i].arrival;
        }
    }
}


void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround = proc[i].burst + proc[i].waiting;
    }
}

void findavgTime(struct Process proc[], int n) {
    findWaitingTime(proc, n);
    findTurnaroundTime(proc, n);
    
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting;
        total_turnaround_time += proc[i].turnaround;
        printf("%d\t%d\t%d\t%d\t%d\n", 
               proc[i].id, 
               proc[i].arrival, 
               proc[i].burst, 
               proc[i].waiting,
               proc[i].turnaround);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process proc[n];
    
       for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Process IDs starting from 1
        printf("Enter arrival time and burst time for Process %d: ", proc[i].id);
        scanf("%d %d", &proc[i].arrival, &proc[i].burst);
    }
    
    findavgTime(proc, n);
    
    return 0;
}
