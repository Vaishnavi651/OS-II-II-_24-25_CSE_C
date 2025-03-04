#include <stdio.h>

int main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10], completion_time[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf("Arrival time is: \t");
        scanf("%d", &at[i]);
        printf("\nBurst time is: \t");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        completion_time[i] = 0; 
    }

    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);

    int ready_queue[10]; 
    int quantum_queue[10]; 
    int ready_count = 0;
    int quantum_count = 0;

    printf("\nProcess No \t\t Burst Time \t\t Arrival Time \t\t TAT \t\t Waiting Time \t Completion Time");
    printf("\nGantt Chart (Textual Representation):\n");

    int current_time = 0;
    for (sum = 0, i = 0; y != 0;) {
        if (at[i] <= current_time && temp[i] > 0) {
            quantum_queue[quantum_count++] = i;

            while (quantum_count > 0) {
                int current_process = quantum_queue[0];
                for(int k = 0; k < quantum_count -1; ++k){
                    quantum_queue[k] = quantum_queue[k+1];
                }
                quantum_count--;

                if (temp[current_process] <= quant && temp[current_process] > 0) {
                    sum += temp[current_process];
                    temp[current_process] = 0;
                    printf(" P%d ", current_process + 1); 

                    completion_time[current_process] = sum;
                    y--;
                    printf("\nProcess No[%d] \t\t %d\t\t %d\t\t\t %d\t\t\t %d\t\t %d", current_process + 1, bt[current_process], at[current_process], sum - at[current_process], sum - at[current_process] - bt[current_process], completion_time[current_process]);
                    wt += sum - at[current_process] - bt[current_process];
                    tat += sum - at[current_process];

                } else if (temp[current_process] > 0) {
                    sum += quant;
                    temp[current_process] -= quant;
                    printf(" P%d ", current_process + 1); 

                    ready_queue[ready_count++] = current_process;
                    break;
                }
                current_time = sum; 
            }

        }
        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
            current_time++;
        }
        if(ready_count > 0){
            for(int k = 0; k < ready_count; ++k){
                quantum_queue[quantum_count++] = ready_queue[k];
            }
            ready_count = 0;
        }
    }

    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;
    printf("\nAverage Turn Around Time: \t%.2f", avg_tat);
    printf("\nAverage Waiting Time: \t%.2f\n", avg_wt);
    return 0;
}

