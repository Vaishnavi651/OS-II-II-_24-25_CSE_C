#include<stdio.h>
void bubblesort(int n,int process[],int burst[],int arrival[]){
	void main(){
		int n;
		printf("Enter the number of processes:");
		scanf("%d",&n);
		int process[n], arrival[n], burst[n];
		for(int i=0;i<n;i++){
			process[i]=i+1;
		}
		printf("Enter arrival time:");
		for(int j=0;j<n;j++){
			scanf("%d",&arrival[n]);
		}
		printf("Enter burst time:");
		for(int k=0;k<n;k++){
			scanf("%d",&burst[n]);
		}
		bubblesort(n,process,arrival,burst);
		
	}

        	void bubblesort(int n,int process[],int arrival[],int burst[]){
			for(int i=0;i<n-1;i++){
				for(int j=0;j<n-1-i;j++){
					if(burst[j]>burst[j+1]){
					int temp_process=process[j];
					process[j]=process[j+1];
					process[j+1]=temp_process;

					int temp_burst=burst[j];
					burst[j]=burst[j+1];
					burst[j+1]=temp_burst;

					int temp_arrival=arrival[j];
					arrival[j]=arrival[j+1];
					arrival[j+1]=temp_arrival;
					}
				}
			}
			int ct[n],wt[n],tt[n];
			ct[0] = arrival[0] + burst[0];
                        for(int i = 1; i < n; i++){
                                if(ct[i-1] < arrival[i]) {
                                  ct[i] = arrival[i] + burst[i];
                                     }
			           	else {
                                          ct[i] = ct[i-1] + burst[i];
                                        }
                                  } 
                                    for(int i = 0; i < n; i++){
                                       tt[i] = ct[i] - arrival[i]; 
                                           wt[i] = tt[i] - burst[i];   
                                        }


		           printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
			    for(int i = 0; i < n; i++){
			            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], burst[i], ct[i], tt[i], wt[i]);
			    }
		}
}


					     














