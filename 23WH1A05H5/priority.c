#include<stdio.h>
#include<stdlib.h>

void bubblesort(int n, int p[], int at[], int bt[], int pt[]);
int main(){
	int n;
	printf("Enter number of processes: ");
	scanf("%d",&n);
	int p[n], at[n], bt[n], pt[n],j=0,wt[n],ct[n],tt[n],i;
	for(i=0;i<n;i++){
		p[i]=j+1;
		printf("\nArrival time of process %d:",p[i]);
		scanf("%d",&at[i]);
		printf("\nBurst time of process %d:",p[i]);
		scanf("%d",&bt[i]);
		printf("\nPriority of process %d:",p[i]);
		scanf("%d",&pt[i]);
		j++;
	}
	bubblesort(n,p,at,bt,pt);
	int total=0;
	for(i=0;i<n;i++){
		if(total<at[i]){
			total=at[i];
		}
		ct[i]=total+bt[i];
		total=ct[i];
	}
	wt[0]=0;
	tt[0]=bt[0]+wt[0];
	for(i=1;i<n;i++){
		wt[i]=ct[i-1]-at[i];
		if(wt[i]<0){
			wt[i]=0;
		}
		tt[i]=bt[i]+wt[i];
	}
	float awt=0,att=0;
	for(int i=0;i<n;i++){
		awt+=wt[i];
		att+=tt[i];
	}
	printf("\nProcessID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tPriority\n");
	for(int i=0;i<n;i++) {
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1,at[i],bt[i],wt[i],tt[i],pt[i]);
	}
	printf("\nAverage Waiting Time: %.2f\n",awt/n);
    printf("Average Turnaround Time: %.2f\n",att/n);
	
}

void bubblesort(int n, int p[], int at[], int bt[], int pt[]){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<(n-i);j++){
	      		if(pt[j]>pt[j+1]){
	      			temp=pt[j+1];
	      			pt[j+1]=pt[j];
	      			pt[j]=temp;
					temp=p[j+1];
					p[j+1]=p[j];
					p[j]=temp;
					temp=at[j+1];
					at[j+1]=at[j];
					at[j]=temp;
					temp=bt[j+1];
					bt[j+1]=bt[j];
					bt[j]=temp;
				}
	     	}
    	}
}
