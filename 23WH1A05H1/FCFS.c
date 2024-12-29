#include <stdio.h>
#include<stdlib.h>
void bubble(int arr[],int burst[], int n){
    for(int i=0;i<n;i++){
         for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                int temp2=burst[j];
                burst[j]=burst[j+1];
                burst[j+1]=temp2;
            }
    }
}
}
void turnaround_time(int comple[],int arri[],int turn[],int n){
    for(int i=0;i<n;i++){
        turn[i]=comple[i]-arri[i];
    }
}
void waiting_time(int turn[],int burst[],int wait[],int n){
    for(int i=0;i<n;i++){
        wait[i]=turn[i]-burst[i];
    }
}
void avg_waittime(int wait[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=wait[i];
    }
    float avg;
    avg=(float)sum/n;
    printf("Average wait time is %.2f\n",avg);
}
void avg_turnaround(int turn[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=turn[i];
    }
    float avg;
    avg=(float)sum/n;
    printf("Average turnover time is %.2f\n",avg);
}
int main() {
    int n;
    scanf("%d",&n);
int proc[n],arr[n],burst[n];
printf("Enter the details for n processes:\n");

for(int i=0;i<n;i++){
printf("Enter arrival time for process %d\n",i);
scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
printf("Enter burst time for process %d\n",i);
scanf("%d",&burst[i]);
}
bubble(arr,burst,n);
for(int i=0;i<n;i++){
printf("Burst time of process %d is %d\n",i,burst[i]);
}
for(int i=0;i<n;i++){
printf("Arrival time of process %d is %d\n",i,arr[i]);
}
int gantt[n];
gantt[0] = arr[0] + burst[0]; 
    for (int i = 1; i < n; i++) {
        if (gantt[i - 1] < arr[i]) {
            gantt[i] = arr[i] + burst[i]; 
        } else {
            gantt[i] = gantt[i - 1] + burst[i];
        }
    }
int tat[n],wait[n];
turnaround_time(gantt,arr,tat,n);
waiting_time(tat,burst,wait,n);

printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
for(int i=0;i<n;i++){
printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,burst[i],gantt[i],tat[i],wait[i]);
}
avg_turnaround(tat,n);
avg_waittime(wait,n);

return 0;
}
