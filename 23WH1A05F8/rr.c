#include <stdio.h>
int main() {
    int p[10],at[10],bt[10],ct[10],tat[10],wt[10],rem_bt[10];
    int i,j,n,time,quantum;
    float awt=0,atat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter %d process IDs: ",n);
    for(i=0;i<n;i++) {
        scanf("%d",&p[i]);
    }
    printf("Enter %d arrival times: ",n);
    for(i=0;i<n;i++) {
        scanf("%d",&at[i]);
    }
    printf("Enter %d burst times: ",n);
    for(i=0;i<n;i++) {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d",&quantum);
    time=0;
    int completed=0;
    while(completed<n) {
        for(i=0;i<n;i++) {
            if(rem_bt[i]>0&&at[i]<=time) {
                if(rem_bt[i]>quantum) {
                    time+=quantum;
                    rem_bt[i]-=quantum;
                } else {
                    time+=rem_bt[i];
                    ct[i]=time;
                    rem_bt[i]=0;
                    completed++;
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    printf("\nP\tA.T\tB.T\tC.T\tTAT\tWT\n");
    for(i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time: %.2f",atat);
    printf("\nAverage Waiting Time: %.2f\n",awt);
    return 0;
}
