#include<stdio.h>
#include<stdlib.h>

void bubblesort(int n, int process[], int arrival[], int burst[]);
void swap(int a, int b);

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int j,i;
    int arrival[n], process[n], burst[n], ct[n], tt[n], wt[n];
    for(j=0;j<n;j++) {
        process[j]=j+1;
    }
    for(i=0;i<n;i++) {
        printf("Arrival time of Process %d: ", process[i]);
        scanf("%d", &arrival[i]);
        printf("Burst time of Process %d: ", process[i]);
        scanf("%d", &burst[i]);
    }
    bubblesort(n, process, arrival, burst);
    int total_time=0;
    int m,l;
    for(m=0;m<n;m++) {
        if(total_time<arrival[m]) {
            total_time=arrival[m];
        }
        ct[m]=total_time+burst[m];
        total_time=ct[m];
    }
    wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=ct[i-1]-arrival[i];
        if(wt[i]<0){
        	wt[i]=0;
		}
    }
    for(j=0;j<n;j++){
    	tt[j]=wt[j]+burst[j];
	}
    
    printf("\nProcessID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i],arrival[i],burst[i],wt[i],tt[i]);
    }
    int avgW=0,avgT=0;
    for(m=0;m<n;m++){
    	avgW+=wt[m];
    	avgT+=tt[m];
	} 
	printf("The average Turnaround time is %.2f\n", (float)avgT / n);
    printf("The average Waiting time is %.2f", (float)avgW / n);
}
void bubblesort(int n, int process[], int arrival[], int burst[]){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(burst[j]>burst[j+1]){
				int temp = burst[j];
                burst[j] = burst[j+1];
                burst[j+1] = temp;

                temp = arrival[j];
                arrival[j] = arrival[j+1];
                arrival[j+1] = temp;
                
                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
			}
		}
	}
}

void swap(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

