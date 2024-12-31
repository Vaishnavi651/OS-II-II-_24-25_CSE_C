#include<stdio.h>
int main() {
    int p[10], at[10], bt[10], ct[10], tat[10], wt[10], i, j, temp = 0, n;
    float awt=0, atat=0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    printf("Enter %d process: ", n);
    for(i=0;i< n;i++) {
        scanf("%d",&p[i]);
    }
    printf("Enter %d arrival times: ", n);
    for(i=0;i<n;i++) {
        scanf("%d",&at[i]);
    }
    printf("Enter %d burst times: ", n);
    for(i=0;i<n;i++) {
        scanf("%d",&bt[i]);
    }
    for(i= 0;i <n - 1;i++) {
        for(j=i+1;j<n;j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++) {
        if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
        } else {
            ct[i]=ct[i-1]+bt[i];
        }
    }
    printf("\nP\tA.T\tB.T\tC.T\tTAT\tWT\n");
    for(i=0;i<n;i++) {
        tat[i] =ct[i]-at[i];
        wt[i] =tat[i]-bt[i];
        atat +=tat[i];
        awt +=wt[i];
    }
    atat =atat/n;
    awt =awt/n;
    for(i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Turnaround Time  %.2f", atat);
    printf("\nAverage Waiting Time  %.2f", awt);
    return 0;
}

