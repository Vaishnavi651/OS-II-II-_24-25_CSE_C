#include <stdio.h>
#include <stdlib.h>

void bubblesort(int count, int processes[], int arrivals[], int bursts[]);

int main() {
    int count;
    printf("Enter the number of processes: ");
    scanf("%d", &count);

    int arrivals[count], processes[count], bursts[count], completion[count], turnaround[count], waiting[count];

    for (int i = 0; i < count; i++) {
        processes[i] = i + 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Arrival time of Process %d: ", processes[i]);
        scanf("%d", &arrivals[i]);
        printf("Burst time of Process %d: ", processes[i]);
        scanf("%d", &bursts[i]);
    }

    bubblesort(count, processes, arrivals, bursts);

    int currentTime = 0;
    for (int i = 0; i < count; i++) {
        if (currentTime < arrivals[i]) {
            currentTime = arrivals[i];
        }
        completion[i] = currentTime + bursts[i];
        currentTime = completion[i];
    }

    for (int i = 0; i < count; i++) {
        turnaround[i] = completion[i] - arrivals[i];
        waiting[i] = turnaround[i] - bursts[i];
    }

    printf("\nProcessID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], arrivals[i], bursts[i], waiting[i], turnaround[i]);
    }

    return 0;
}


void bubblesort(int count, int processes[], int arrivals[], int bursts[]) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (arrivals[j] > arrivals[j + 1]) {
                // Swap arrivals
                int temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;

                // Swap processes
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                // Swap bursts
                temp = bursts[j];
                bursts[j] = bursts[j + 1];
                bursts[j + 1] = temp;
            }
        }
    }
}
