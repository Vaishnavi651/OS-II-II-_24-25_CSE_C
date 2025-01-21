//PRIORITY SCHEDULLING
#include <stdio.h>

int main() {
    int n,arr[n], bur[n], p[n], ct[n], tat[n], wait[n];
    printf("Enter the no of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter arrival time :\n");
        scanf("%d",&arr[i]);
        printf("Enter burst time: \n");
        scanf("%d",&bur[i]);
        printf("Enter priority:   \n");
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j]>p[j+1]){
            int temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
                temp=arr[j];
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
        for(int i=1;i<n;i++){
            ct[i]=ct[i-1]+bur[i];
            tat[i]=ct[i]-arr[i];
            wait[i]=tat[i]-bur[i];
        }
        printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", i + 1, arr[i], bur[i], p[i], ct[i], tat[i], wait[i]);
    }
       return 0;
    }
 