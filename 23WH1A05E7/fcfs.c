#include<stdio.h>
int main(){
	int p[10],at[10],bt[10],tat[10],wt[10],ct[10],n,i,j,temp;
	float awt=0,atat=0;
	printf("enter the number of processes:");
	scanf("%d",&n);
	printf("enter the processes:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
		}
	printf("enter arrival time:");
	for(i=0;i<n;i++){
	scanf("%d",&at[i]);
	}
	printf("enter burst time:");
	for(i=0;i<n;i++){
	scanf("%d",&bt[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<(n-i-1);j++){
			if(at[j]>at[j+1]){
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
	ct[0]=at[0]+bt[0];
	for(i=1;i<n;i++){
	temp=0;
		if(ct[i-1]<at[i]){
			 temp=at[i]-ct[i-1];
			 }
		ct[i]=ct[i-1]+bt[i]+temp;
		}
		
	printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
	for(i=0;i<n;i++){
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		atat=atat+tat[i];
		awt=awt+wt[i];
		}
		atat=atat/n;
		awt=awt/n;
		for(i=0;i<n;i++){
			printf("\np%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
			}
			printf("average turnaroundtime is:%f",atat);
			printf("average waiting time is:%f",awt);
			return 0;
		}
		
			
	
