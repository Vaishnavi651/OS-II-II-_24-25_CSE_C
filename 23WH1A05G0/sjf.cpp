#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
} Process;

void sort(Process p[], int n) {
    
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].burst_time > p[j].burst_time || 
                (p[i].burst_time == p[j].burst_time && p[i].arrival_time > p[j].arrival_time)) {
                
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].process_id = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
    }

    
    sort(p, n);

    
    p[0].waiting_time = 0;  
    p[0].turn_around_time = p[0].burst_time;  

    for (int i = 1; i < n; i++) {
        
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time - p[i].arrival_time;
        if (p[i].waiting_time < 0) {
            p[i].waiting_time = 0;  
        }

        
        p[i].turn_around_time = p[i].waiting_time + p[i].burst_time;
    }

    
    float total_waiting_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turn_around_time += p[i].turn_around_time;
    }
    

    
    printf("\nProcesses  Burst Time  Waiting Time  Turn-Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].process_id, p[i].burst_time, p[i].waiting_time, p[i].turn_around_time);
    }

    printf("\nAverage waiting time = %.2f\n", total_waiting_time / n);
    printf("Average turn-around time = %.2f\n", total_turn_around_time / n);

    return 0;
}

