#include<stdio.h>
void bubblesort(int n,int process[],int arrival[],int burst[]);
void main(){
	int n;
	printf("enter the number of processes:");
	scanf("%d",&n);

	int arrival[n];
	int process[n];
	int burst[n];
	for(int i=0;i<n;i++){
		process[i]=i+1;
	}
	printf("enter arrival times:");
	for(int i=0;i<n;i++){
		scanf("%d",&arrival[i]);
	}
	printf("enter burst times:");
	for(int i=0;i<n;i++){
		scanf("%d",&burst[i]);
	}
	bubblesort(n,process,arrival,burst);
	int ct[n],tt[n],wt[n];
	int total_time=0;
	for(int m = 0; m < n; m++) {
        if(total_time < arrival[m]) {
            total_time = arrival[m];
        }
        ct[m] = total_time + burst[m];
        total_time = ct[m];
    }

   	 for(int l = 0; l < n; l++) {
        	tt[l] = ct[l] - arrival[l];
       		 wt[l] = tt[l] - burst[l];
    }
	 printf("\nprocess\tburst time\twaiting time\tturn-around time\n");
	 for(int i=0;i<n;i++){
		 printf("%d\t%d\t%d\t%d\n",process[i],burst[i],wt[i],tt[i]);
	 }
}
void bubblesort(int n, int process[],int arrival[],int burst[]){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(burst[j]>burst[j+1]){
					int temp;
					
					temp=burst[j];
					burst[j]=burst[j+1];
					burst[j+1]=temp;

					temp=arrival[j];
					arrival[j]=arrival[j+1];
					arrival[j+1]=temp;

					temp=process[j];
					process[j]=process[j+1];
					process[j+1]=temp;
			}
		}
	}
}
