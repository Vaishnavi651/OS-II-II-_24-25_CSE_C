#include<stdio.h> 

void findWaitingTime(int processes[], int n, int bt[], int wt[]){
	wt[0] = 0;
	for(int i = 1;i<n;i++){
		wt[i] = bt[i-1]+wt[i-1];
	}
}

void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[]){
	for(int i=0;i<n;i++){
		tat[i] = wt[i]+bt[i];
	}
}

void findAvgTime(int processes[], int n, int bt[]){
	int total_wt = 0,total_tat = 0,wt[n],tat[n];
	findWaitingTime(processes,n,bt,wt);
	findTurnAroundTime(processes,n,bt,wt,tat);
	printf("Processes       Burst Time      Waiting Time     Turn Around Time\n");
	for(int i=0;i<n;i++){
		total_wt += wt[i];
		total_tat += tat[i];
		printf("%d",i+1);
		printf("	%d",bt[i]);
		printf("	%d",wt[i]);
		printf(" 	%d\n",tat[i]);
	}
	float avg_wt = (float)total_wt / (float)n;
	float avg_tat = (float)total_tat / (float)n;
	printf("Average Waiting Time is %f\n",avg_wt);
	printf("Average Turn Around Time is %f\n",avg_tat);
}
int main(){
	int n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int processes[n],bt[n];
	for(int i=0;i<n;i++){
		printf("Enter the process id  and the  burst time of %d\n",i+1);
		scanf("%d%d",&processes[i],&bt[i]);
	}
	findAvgTime(processes,n,bt);
	return 0;
}
