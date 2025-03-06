
#include<stdio.h>


int main(){
	int n,m;
	printf("Enter nuumber of processes");
	scanf("%d",&n);
	printf("enter number of resources");
	scanf("%d",&m);
	int res[100];
	printf("Enter total  number of instances");
	for(int i=0;i<m;i++){
		scanf("%d",&res[i]);
	}
	printf("enter allocation matrix");
	int all[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&all[i][j]);
		}
	}

	printf("enter max matrix");
	int max[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
	}
	int need[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j]=max[i][j]-all[i][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}

	int sum[m];
	int k=0;
	for(int i=0;i<m;i++){
		sum[i]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			sum[i]+=all[j][i];
		}
		
	}

	for(int i=0;i<m;i++){
		printf("%d\t",sum[i]);
	}
	printf("\n");
	int avail[m];
	for(int i=0;i<m;i++){
		avail[i]=res[i]-sum[i];
	}
	for(int i=0;i<n;i++){
		printf("%d\t" ,avail[i]);
	}
	printf("\n");
	int work[m];
	int finish[n];
	int count=0;
	for(int i=0;i<n;i++){
		finish[i]=0;
	}

	for(int i=0;i<m;i++){
		work[i]=avail[i];
	}

	while(count<n){
		int found=0;
		for(int i=0;i<n;i++){
			if(finish[i]==0){
				int exe=1;
				for(int j=0;j<m;j++){
					if(need[i][j]>work[j]){
						exe=0;
						break;
					}
				}
				if(exe==1){
					for(int j=0;j<m;j++){
						work[j]+=all[i][j];
					}count++;
					finish[i]=1;
					found=1;
					break;
				}
			}
		}
		if(found==0){
			
			printf("System is in unsafe state");
			return 0;
		}
	}
		
		printf("System is in safe state");
}

	
