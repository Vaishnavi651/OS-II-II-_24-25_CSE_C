#include <stdio.h>
#include <stdlib.h>
void sort(int n,int p[100],int at[100],int bt[100]){
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++){
			if(at[i] > at[j])
			{
				int c = at[i];
				at[i] = at[j];
				at[j] = c;
				int k = bt[i];
				bt[i]=bt[j];
				bt[j] = k;
				int d = p[i];
				p[i]=p[j];
				p[j]=d;
			}
		}
	}
	for(int i =0;i<n;i++){
		printf("%d %d %d\n",p[i],at[i],bt[i]);}
}

int main(){
	int n;
	printf("enter the no.of proccesses to analyse :");
	scanf("%d",&n);
	int bt[100],at[100],tt[100],ct[100],wt[100],p[100];
	printf("enter the arrival time and brust time of proccesses:");
	for(int i =0;i<n;i++){
		p[i]=i+1;
		scanf("%d %d",&at[i],&bt[i]);
	}
	sort(n,at,p,bt);
	int sum=0,sum1=0,sum2=0;
	for (int x=0;x<n;x++){
		sum = sum+bt[x];
		ct[x] = sum;
		printf("%d\n",ct[x]);

	}
	for(int c =0;c<n;c++){
		tt[c] = ct[c] - at[c];
	}
	for(int g=0;g<n;g++){
		wt[g] = tt[g]- bt[g];
	}
	for(int y=0;y<n;y++){
		sum1 = sum1+ tt[y];
		sum2 = sum2+wt[y];
	}

       printf("the completion time , turn around time,waiting time are:");
      for(int x=0;x<n;x++){
	     printf("%d  %d  %d",ct[x],tt[x],wt[x]);
	    printf("\n");
      }

     printf("The avg tt is : %d ",sum1/n);
    printf("the avg wt is : %d",sum2/n);

   return 0;
}



