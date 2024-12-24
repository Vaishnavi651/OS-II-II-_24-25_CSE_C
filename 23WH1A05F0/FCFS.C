#include <stdio.h>
typedef struct {
	int pid;
	int AT;
	int BT;
	int CT;
	int TT;
	int WT;
} Process;

void sort(Process processes[], int n){
	Process temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n+1;j++){
			if(processes[i].AT>processes[j].AT){
				temp = processes[i];
				processes[i]=processes[j];
				processes[j]=temp;
			}
		}
	}
}

void fcfs(Process processes[], int n){
	int currentT=0;
	for(int i = 0; i<n;i++){
		if(currentT<processes[i].AT){
			currentT = processes[i].AT;
		}
		processes[i].CT = currentT + processes[i].BT;
		processes[i].TT = processes[i].CT - processes[i].AT;
		processes[i].WT = processes[i].TT- processes[i].BT;
		currentT = processes[i].CT;
	}
}

void result(Process processes[], int n){
	printf("Pid\t\tAT\t\tBT\t\tCT\t\tTT\t\tWT\n");
	for(int i =0 ; i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].pid,processes[i].AT,processes[i].BT,processes[i].CT,processes[i].TT,processes[i].WT);}
}

int main(){
	int n;
	printf("enter number of processes:");
	scanf("%d",&n);
	Process processes[n];
	for(int i =0; i<n; i++){
		processes[i].pid = i+1;
		printf("Enter AT and BT for process %d:",i+1);
		scanf("%d %d", &processes[i].AT, &processes[i].BT);
	}
sort(processes,n);
fcfs(processes,n);
result(processes, n);
return 0;
}
