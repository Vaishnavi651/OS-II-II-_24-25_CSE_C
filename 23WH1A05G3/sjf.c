#include<stdio.h>
void bubblesort(int n, int process[], int arrival[], int brust[]);

int main()
{
	int n;
	printf("enter number of processes: ");
	scanf("%d",&n);

	int process[n];
	int arrival[n];
	int brust[n];

	for(int i=0; i<n; i++)
	{
		process[i] = i+1;
	}

	printf("enter arrival times: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arrival[i]);
	}

	printf("enter brust times: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&brust[i]);
	}

	bubblesort(n, process, arrival, brust);

	int ct[n], wt[n], tt[n];
	int total_time = 0;

	for (int i = 0; i < n; i++) {
		if (total_time < arrival[i])	
		{
			total_time = arrival[i];
       		}
        ct[i] = total_time + brust[i];
        total_time = ct[i];
    	}
       
	for (int i = 0; i < n; i++) {
		tt[i] = ct[i] - arrival[i];
		wt[i] = tt[i] - brust[i];
    	}
	printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival[i], brust[i], ct[i], tt[i], wt[i]);
	}

    return 0;
}
	void bubblesort(int n, int process[], int arrival[], int brust[])
	{
		int temp;
		for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				if(brust[j]>brust[j+1])
				{
					temp = arrival[j];
					arrival[j] = arrival[j+1];
					arrival[j+1] = temp;

					temp = brust[i];
					brust[i] = brust[i+1];
					brust[i+1] = temp;

					temp = process[i];
					process[i] = process[i+1];
					process[i+1] = temp;
				}
			}
		}
	}

