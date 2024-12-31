#include<stdio.h>

int main()
{
    int burst_time[20], process[20], waiting_time[20], turnaround_time[20];
    int i, j, num_processes, total_waiting_time = 0, total_turnaround_time = 0, position, temp;

    float avg_waiting_time, avg_turnaround_time;


    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("\nEnter Burst Times for each process:\n");
    for (i = 0; i < num_processes; i++) {
        printf("p%d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }

    for (i = 0; i < num_processes; i++) {
        position = i;
        for (j = i + 1; j < num_processes; j++) {
            if (burst_time[j] < burst_time[position])
                position = j;
        }

      
        temp = burst_time[i];
        burst_time[i] = burst_time[position];
        burst_time[position] = temp;

        
        temp = process[i];
        process[i] = process[position];
        process[position] = temp;
    }

     waiting_time[0] = 0;

    for (i = 1; i < num_processes; i++) {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++) {
    
            waiting_time[i] += burst_time[j];
        }

   
        total_waiting_time += waiting_time[i];
    }

    avg_waiting_time = (float)total_waiting_time / num_processes;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];


        printf("p%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    avg_turnaround_time = (float)total_turnaround_time / num_processes;

    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);

    return 0;
}

