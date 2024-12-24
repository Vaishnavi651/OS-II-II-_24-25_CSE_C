#include<stdio.h>
int main(){

int p[30],n,at[30],bt[30],tt[30],ct[30],wt[30],i,j,temp=0;
float awt=0,att=0;
printf("Enter the size of array:");
scanf("%d",&n);
printf("The size of array is %d",n);
for(i=0;i<n;i++){
	scanf("%d",&p[i]);
}
for(i=0;i<n;i++){
	scanf("%d",&at[i]);
}
for(i=0;i<n;i++){
	scanf("%d",&bt[i]);
}
for(i=0;i<n;i++){
	for(j=0;j<(n-i);j++){
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
for(i=1;i<n;i++)
    {  
	    temp=0;
     if(ct[i-1]<at[i])
     {
        temp=at[i]-ct[i-1];
     }
     ct[i]=ct[i-1]+bt[i]+temp;
    }
printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
for(i=0;i<n;i++)
    {
    tt[i]=ct[i]-at[i];
    wt[i]=tt[i]-bt[i];
    att+=tt[i];
    awt+=wt[i];
    }
    att=att/n;
    awt=awt/n;
    for(i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d \t %d \t %d",p[i],at[i],bt[i],ct[i],tt[i],wt[i]);
    }
    printf("\naverage turnaround time is %f",att);

    printf("\naverage wating timme is %f",awt);
    return 0;
}
