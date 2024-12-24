#include<stdio.h>
#include<stdlib.h>

void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

float avg(int a[],int n){
	float sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
	}
	return sum=sum/n;
}

void bubblesort(int a[], int p[], int bt[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                swap(&a[i], &a[j]);
                swap(&p[i], &p[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }
}

int main(){
	int n;
	printf("ENTER no of ELEMENT : ");
	scanf("%d",&n);
	int a[n];
	int p[n];
	int bt[n];
       
        for(int i=0;i<n;i++){
                p[i]=i+1;
        }

        printf("ENTER arrival time :\n ");
	for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
       printf("ENTER burst time time :\n ");
        for(int i=0;i<n;i++){
                scanf("%d",&bt[i]);
        }

	printf("arrival time : ");

	bubblesort(a,p,bt,n);
	/*for(int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
        printf("burst time :");

     
        for(int i=0;i<n;i++){
                printf("%d\t",bt[i]);
        }
        printf("prcs :");

       
        for(int i=0;i<n;i++){
                printf("%d\t",p[i]);
        }*/
	int c[n];
	c[0]=a[0]+bt[0];
	for(int i=1;i<n;i++){
                c[i]=bt[i]+c[i-1];
        }
	int tt[n];
	for(int i=0;i<n;i++){
                tt[i]=c[i]-a[i];
        }
	int wt[n];
	for(int i=0;i<n;i++){
                wt[i]=tt[i]-bt[i];
        }
	/*
	printf("wait time :");
        for(int i=0;i<n;i++){
                printf("%d\t",wt[i]);
        }
        printf("complete time :");

        for(int i=0;i<n;i++){
                printf("%d\t",c[i]);
        }
	printf("total time :");

        for(int i=0;i<n;i++){
                printf("%d\t",tt[i]);
        }*/
	
	printf("\n%-8s%-15s%-15s%-18s%-15s\n", "Process", "Arrival Time", "Burst Time", "Turnaround Time", "Waiting Time");
        for (int i = 0; i < n; i++) {
        printf("%-8d%-15d%-15d%-18d%-15d\n", p[i], a[i], bt[i], tt[i], wt[i]);
         }

	printf("avg waiting time :%f\n",avg(wt,n));
	printf("avg turn around  time :%f ",avg(tt,n));









}

