#include<stdio.h>
int main(){
	int n,i,y,sum=0,count=0,wt=0,quant=0,tat=0,at[10],bt[10],temp[10];
	float avg_wt,avg_tat;
	printf("enter total number of processes:");
	scanf("%d",&n);
	y=n;
	printf("enter arrival time and burst time:");
	for(i=0;i<n;i++){
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	printf("enter time quantum for the processes:");
	scanf("%d",&quant);
	printf("\nProcess No\t\tBurst time\t\tTAT\t\t\t\tWaiting time");
	for(sum=0,i=0;y!=0;){
		if(temp[i]<=quant&&temp[i]>0){
			sum=sum+temp[i];
			temp[i]=0;
			count=1;
		}else if(temp[i]>0){
			temp[i]=temp[i]-quant;
			sum=sum+quant;
		}
		if(temp[i]==0&&count==1){
			y--;
			printf("\nProcess[%d]\t\t%d\t\t\t\t%d\t\t\t%d",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
			wt=wt+sum-at[i]-bt[i];
			tat=tat+sum-at[i];
			count=0;
			}
		if(i==n-1){
			i=0;
		}
		else if(at[i+1]<=sum){
			i++;
		}
		else{
			i=0;
		}
	}
	avg_wt=wt*1.0/n;
	avg_tat=tat*1.0/n;
	printf("\n Average waiting time:\t%f",avg_wt);
printf("\n AVerage turn around time:\t%f",avg_tat);
}


