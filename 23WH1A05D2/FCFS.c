#include<stdio.h>

//Function to fint waiting time
void findWaitingTime(int processes[], int n, int bt[], int wt[]){
    //for the first arrived process waiting time is "0"
    wt[0] = 0;
    int i;
    for(i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
}

//Function to find turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]){
	int i;
    for(i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }
}

//Function to find average time
void findAvgTime(int processes[], int n, int bt[]){
    int wt[n], tat[n], total_wt=0, total_tat=0;
    int i;
    
    findWaitingTime(processes, n, bt, wt);
    
    findTurnAroundTime(processes, n, bt, wt, tat);
    
    printf("Process   Brust   Waiting   TurnAround\n");
    
    for(i=0; i<n; i++){
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("  %d  ", i+1);
        printf("     %d  ", bt[i]);
        printf("      %d   ", wt[i]);
        printf("       %d    \n", tat[i]);
    }
    
    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    
    printf("Average waiting time : %f", avg_wt);
    printf("\nAverage turn around time : %f", avg_tat);
}

int main(){
    int n;
    int i;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    int processes[n], bt[n];
    for(i=0; i<n; i++){
        printf("Enter processes id and brust time of process %d\t", i+1);
        scanf("%d  %d", &processes[i], &bt[i]);
    }
    findAvgTime(processes, n, bt);
    
    return 0;
}
