#include<stdio.h>
void waitingtime(int p[],int n,int b[],int w[]){
        w[0]=0;
        for(int i=1;i<n;i++){
                w[i]=b[i-1]+w[i-1];
        }
}

void turnaroundtime(int p[],int n,int tat[],int b[],int w[]){
        for(int i=0;i<n;i++){
                tat[i]=b[i]+w[i];
        }
}

void findavg(int p[],int n,int b[]){
        int w[n],tat[n],total_wt=0,total_tat=0;
        waitingtime(p,n,b,w);
        turnaroundtime(p,n,tat,b,w);
        printf("Process\tArrival\tBurst time\tWaiting time\tTurnaroundtime\n");
        for(int i=0;i<n;i++){
                total_wt=total_wt+w[i];
                total_tat=total_tat+tat[i];

                printf(" %d\t ", (i + 1));
                printf("%d\t",p[i]);
                printf("%d\t\t ", b[i]);
                printf("%d\t\t", w[i]);
                printf("%d\n",tat[i]);
        }

        int weight=(float)total_wt/(float)n;
        int turntime=(float)total_tat/(float)n;
        printf("\nAverage waiting time : %d",weight);
        printf("\n");
        printf("Average turnaround time : %d",turntime);
}

int main(){
        int p[]={1,2,3};
        int n=sizeof(p)/sizeof(p[0]);
        int b[]={6,7,9};
        findavg(p,n,b);

}
