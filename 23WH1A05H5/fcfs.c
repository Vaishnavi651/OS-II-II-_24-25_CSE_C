#include<stdio.h>
#include<stdlib.h>

void bubblesort(int n, int process[], int arrival[], int burst[]);

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival[n], process[n], burst[n], ct[n], tt[n], wt[n];
    for(int j=0;j<n;j++) {
        process[j]=j+1;
    }
    for(int i=0;i<n;i++) {
        printf("Arrival time of Process %d: ", process[i]);
        scanf("%d", &arrival[i]);
        printf("Burst time of Process %d: ", process[i]);
        scanf("%d", &burst[i]);
    }
    bubblesort(n, process, arrival, burst);
    int total_time=0;
    for(int m=0;m<n;m++) {
        if(total_time<arrival[m]) {
            total_time=arrival[m];
        }
        ct[m]=total_time+burst[m];
        total_time=ct[m];
    }
    for(int l=0;l<n;l++) {
        tt[l]=ct[l]-arrival[l];
        wt[l]=tt[l]-burst[l];
    }
    printf("\nProcessID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i],arrival[i],burst[i],wt[i],tt[i]);
    }
}

void bubblesort(int n, int process[], int arrival[], int burst[]) {
    for(int a=0;a<n-1;a++) {
        for(int b=0;b<n-1-a;b++) {
            if(arrival[b]>arrival[b+1]) {
                int temp;
                temp=arrival[b];
                arrival[b]=arrival[b+1];
                arrival[b+1]=temp;
                temp=process[b];
                process[b]=process[b+1];
                process[b+1]=temp;
                temp=burst[b];
                burst[b]=burst[b+1];
                burst[b+1]=temp;
            }
        }
    }
}
