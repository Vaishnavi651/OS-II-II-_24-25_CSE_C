//SJF SCHEDULLING
#include <stdio.h>

int main() {
    int n;
     printf("Enter the no of processes: ");
    scanf("%d",&n);
    int arr[n], bur[n], p[n], ct[n], tat[n], wait[n];
   
    for(int i=0;i<n;i++){
        printf("Enter arrival time :\n");
        scanf("%d",&arr[i]);
        printf("Enter burst time: \n");
        scanf("%d",&bur[i]);
     
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j] > arr[j + 1] || 
                (arr[j] == arr[j + 1] && bur[j]>bur[j+1])){
               
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                temp=bur[j];
                bur[j]=bur[j+1];
                bur[j+1]=temp;
                
            }
        }
        }
          
        ct[0]=arr[0]+bur[0];
        tat[0]=ct[0]-arr[0];
        wait[0]=tat[0]-bur[0];
        if (wait[0] < 0) wait[0] = 0;
        for(int i=1;i<n;i++){
            if(ct[i-1]<arr[i]){
                ct[i]=arr[i]+bur[i];
            }
            else{
            ct[i]=ct[i-1]+bur[i];
            }
            tat[i]=ct[i]-arr[i];
            wait[i]=tat[i]-bur[i];
            if(wait[i]<0){
                wait[i]=0;
            }
        }
        printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arr[i], bur[i], ct[i], tat[i], wait[i]);
    }
       return 0;
    }
 