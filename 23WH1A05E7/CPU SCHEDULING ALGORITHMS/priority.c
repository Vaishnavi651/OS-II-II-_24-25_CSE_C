#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int n,i,bt[10],at[i],p[10],index[10];
	printf("enter the number of processes");
	scanf("%d",&n);
	printf("enter burst time and priority:");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		scanf("%d",&p[i]);
		index[i]=i+1;
	}
	for(i=0;i<n;i++){
		int a=p[i],m=i;
		for(int j=1;j<n;j++){
			if(p[j]>a){
				a=p[j];
				m=j;
			}
		}
		swap(&p[i],&p[m]);
		swap(&bt[i],&bt[m]);
		swap(&index[i],&index[m]);
	}
	int t=0;
	    printf("Order of process Execution is\n");

   	 for(int i=0;i<n;i++)

    	{

       		 printf("P%d is executed from %d to %d\n",index[i],t,t+bt[i]);

        	t+=bt[i];

    }

    	printf("\n");

    	printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");

    	int wait_time=0;

   	 for(int i=0;i<n;i++)

    		{

       		 printf("P%d          %d          %d          %d\n",index[i],bt[i],wait_time,wait_time + bt[i]);

       		 wait_time += bt[i];

    }

    return 0;

}
