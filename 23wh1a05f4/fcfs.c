#include<stdio.h>
struct process{
	int id;
	int arrivaltime;
	int bursttime;
	int waitingtime;
	int turnaroundtime;
	};
void calculatewaitingtime(struct process processes[],int n)
{
processes[0].waitingtime=0;
for(int i=1;i<n;i++)
{
processes[i].waitingtime=processes[i-1].waitingtime+processes[i-1].bursttime;
}
}

void calculateturnaroundtime(struct process processes[], int n)
{
for(int i=0;i<n;i++)
processes[i].turnaroundtime=processes[i].waitingtime+processes[i].bursttime;
}

void calculateaveragetimes(struct process processes[],int n)
{
float totalwaitingtime=0,totalturnaroundtime=0;
for(i=0;i<n;i++)
totalwaitingtime+=processes[i].waitingtime;
totalturnarountime+=processes[i].turnaroundtime;
}
printf("Average waiting time=%.2f\n",
