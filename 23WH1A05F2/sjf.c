#include<stdio.h>
void main()
{
	int p[10],at[10],bt[10],ct[10],tt[10],wt[10],n,i,j,temp,min,pos;
	int att=0,awt=0;
	printf("enter no of processes:");
	scanf("%d",&n);
	printf("enter processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("enter arrival times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("enter burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(at[i]>at[j]||at[i]==at[j]&&bt[i]>bt[j])
			{
				temp=p[i];
				p[i]==p[j];
				p[j]=temp;

				temp=at[i];
				at[i]=at[j];
				at[j]=temp;

				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
			}
		}
	}
	ct[0]=at[0]+bt[0];
	for(i=1;i<n;i++)
	{
		min=1000;
		pos=-1;
		for(j=i;j<n;j++)
		{if(at[j]<=ct[i-1]&&bt[j]<min)
			{
				min=bt[j];
				pos=j;
			}
		}

		int temp = p[i];
       		 p[i] = p[pos];
       		 p[pos] = temp;

       		 temp = at[i];
       		 at[i] = at[pos];
       		 at[pos] = temp;

       		 temp = bt[i];
       		 bt[i] = bt[pos];
       		 bt[pos] = temp;
		
		 ct[i]=ct[i-1]+bt[i];
	}

	for(i=0;i<n;i++)
	{
		tt[i]=ct[i]-at[i];
		wt[i]=tt[i]-bt[i];
		att+=tt[i];
		awt+=wt[i];
	}
	att/=n;
	awt/=n;
	printf("\nP\tAT\tBT\tCT\tTAT\tWT");
	for(i=1;i<n;i++)
	{
		   printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i], at[i], bt[i], ct[i], tt[i], wt[i]);
	}
	printf("avg tt is \n%d\n",att);
	printf("avg wa is %d\n",awt);





}	
