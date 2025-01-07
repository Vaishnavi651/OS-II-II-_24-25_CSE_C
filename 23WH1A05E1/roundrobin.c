#include<stdio.h>
int main(){
	int n,i,time,remaining,tq;
	int bt[10],wt[10],at[10],tat[10],rt[10];
	float avg_tat=0,avg_wt=0;
	printf("Enter the number of proccesses:");
	scanf("%d",&n);
	printf("Enter the time quantum:");
	scanf("%d",&tq);
	for(i=0;i<n;i++){
		printf("Enter the aarrival time %d:",i+1);
		scanf("%d",&at[i]);
		printf("Enter the brust time %d:",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	remaining = n; 
    for (i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

  
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) { 
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    remaining--;
                    tat[i] = time - at[i];      
                    wt[i] = tat[i] - bt[i];     
                }
            }
        }
    }

    
    for (i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    
    printf("\nProcesses\tArrival Time\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    
    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turn-Around Time = %.2f\n", avg_tat / n);

    return 0;
}



