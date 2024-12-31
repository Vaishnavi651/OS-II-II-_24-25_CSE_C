#include<stdio.h>
#include<stdlib.h>

void swap(int *i, int *j) {
    int temp = *j;
    *j = *i;
    *i = temp;
}

float avg(int a[], int n){
    float sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum / n;
}

void sjfsort(int bt[], int p[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
}

int main(){
    int n;
    printf("ENTER no of ELEMENT : ");
    scanf("%d", &n);
    
    int a[n];  
    int p[n];  
    int bt[n]; 
    int c[n];  
    int tt[n]; 
    int wt[n]; 

   
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }

    printf("ENTER arrival time :\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("ENTER burst time :\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }

    
    sjfsort(bt, p, n);

    
    c[0] = a[0] + bt[0]; 
    for(int i = 1; i < n; i++){
        c[i] = bt[i] + c[i-1];
    }

    
    for(int i = 0; i < n; i++){
        tt[i] = c[i] - a[i];
    }

   
    for(int i = 0; i < n; i++){
        wt[i] = tt[i] - bt[i];
    }

    
    printf("\n%-8s%-15s%-15s%-18s%-15s\n", "Process", "Arrival Time", "Burst Time", "Turnaround Time", "Waiting Time");
    for(int i = 0; i < n; i++){
        printf("%-8d%-15d%-15d%-18d%-15d\n", p[i], a[i], bt[i], tt[i], wt[i]);
    }

    
    printf("Average waiting time: %f\n", avg(wt, n));
    printf("Average turnaround time: %f\n", avg(tt, n));

    return 0;
}

