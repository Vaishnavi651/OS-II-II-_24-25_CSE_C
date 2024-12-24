#include<stdio.h>
#include<stdbool.h>
#define n 3
void bubblesort(int arr[],int bur[],int proc[]){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
					int t = bur[j];
					bur[j] = bur[j+1];
					bur[j+1] = t;
					int t1 = proc[j];
					proc[j] = proc[j+1];
					proc[j+1] = t1;
			}
		}
	}
}
void turnaroundtime(int gantt[],int arr[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i] = gantt[i] - arr[i];
	}
}
void waitingtime(int tat[],int bur[],int wt[]){
	for(int i=0;i<n;i++){
		wt[i] = tat[i] - bur[i];
	}
}


void main(){
	int arr[n];
	int proc[n];
	int bur[n];
	printf("Enter the processes: ");
	for(int i=0;i<n;i++){
		scanf("%d",&proc[i]);
	}
	printf("Enter the arrival times: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the burst times: ");
	for(int i=0;i<n;i++){
		scanf("%d",&bur[i]);
	}

	bubblesort(arr,bur,proc);
	int gantt[n];
	gantt[0] = arr[0]+bur[0];
	for(int i=1;i<n;i++){
		gantt[i] = gantt[i-1] + bur[i];
	}
	int tat[n];
	int wt[n];
	turnaroundtime(gantt,arr,tat);
	waitingtime(tat,bur,wt);
	printf("The TURN AROUND TIMES are: ");
	int st = 0, sw = 0;
	for(int i=0;i<n;i++){
		st+=tat[i];
		printf("\nProcess - %d , Turn around time - %d",proc[i],tat[i]);
	}
	printf("\nThe AVERAGE TURN AROUND TIME is %d",st/n);

	printf("\nThe WAITING TIMES are: ");
	for(int i=0;i<n;i++){
		sw+=wt[i];
		printf("\nProcess - %d , Waiting time - %d",proc[i],wt[i]);
	}
	
	printf("\nThe AVERAGE WAITING TIME is %d",sw/n);
}
