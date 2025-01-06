#include<stdio.h>
#include<stdlib.h>

void roundRobin(int n, int bt[], int quantum){
    int rem_bt[n],wt[n],tt[n],i;
    for(i =0;i<n;i++){
        rem_bt[i]=bt[i];
        wt[i]=0;
    }
    int t=0;
    while(1){
        int done=1;
        for(i=0;i<n;i++){
            if(rem_bt[i]>0){
                done=0;
                if(rem_bt[i]>quantum){
                    t+=quantum;
                    rem_bt[i]-=quantum;
                }else{
                    t+=rem_bt[i];
                    wt[i]=t-bt[i];
                    rem_bt[i]=0;
                }
            }
        }
        if(done==1){
            break;
        }
    }
    for(i=0;i<n;i++){
        tt[i]=wt[i]+bt[i];
    }
    printf("\nProcessID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1,bt[i],wt[i],tt[i]);
    }
    float awt=0, att=0;
    for(i=0;i<n;i++){
        awt+=wt[i];
        att+=tt[i];
    }

    printf("\nAverage Waiting Time: %.2f\n",awt/n);
    printf("Average Turnaround Time: %.2f\n",att/n);
}

int main(){
    int n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n];
    printf("Enter the burst time of each process:\n");
    for (int i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d",&quantum);
    roundRobin(n,bt,quantum);
    return 0;
}
