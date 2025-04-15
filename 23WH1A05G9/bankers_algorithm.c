#include<stdio.h>
int main(){
int n,p[100],need[100][100],res,tat[100],max[100][100],work[100],avail[100],sum[100],all[100][100],seq[100];
printf("enter the number of processes:");
scanf("%d",&n);
printf("enter the number of resourses");
        scanf("%d",&res);
printf("enter the total resourses:");
for(int i=0;i<res;i++){
scanf("%d",&tat[i]);
}
printf("enter the process ids:");
        for(int i=0;i<n;i++){
                scanf("%d",&p[i]);
        }

printf("enter the allocated for each process");
for(int i=0;i<n;i++){
        for(int j=0;j<res;j++) {
                scanf("%d",&all[i][j]);
        }
}
printf("enter the maximum");
for(int i=0;i<n;i++){
        for(int j=0;j<res;j++){
                scanf("%d",&max[i][j]);
        }
}
for (int i = 0; i < n; i++) {
        for (int j = 0; j < res; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
for(int i=0;i<res;i++){
        sum[i]=0;
}
for(int i=0;i<res;i++){
        for(int j=0;j<n;j++){
                sum[i]=sum[i]+all[j][i];
        }
}
for(int i=0;i<res;i++){
        avail[i] = tat[i]-sum[i];
}
for(int i=0;i<res;i++){
        work[i]=avail[i];
}
int finish[n];
int count=0;
int safeidx=0;
for(int i=0;i<n;i++){
        finish[i]=0;
}
while(count<n){
        int found=0;
        for(int i=0;i<n;i++){
                if(finish[i]==0){
                        int exe=1;
                        for(int j=0;j<res;j++){
                                if(need[i][j]>work[j]){
                                        exe=0;
                                        break;
                                }
                        }
                if(exe==1){
                        for(int j=0;j<res;j++){
                                work[j]+=all[i][j];
                        }
                        count++;
                        finish[i]=1;
                        found=1;
                        seq[safeidx++] = p[i];
                        break;
                }
        }
}
if(found==0){
        printf("System is in unsafe state\n");
        return 1;
}
}
printf("System is in safe state");
for(int i=0;i<n;i++){
printf("%d ",seq[i]);
}
}
