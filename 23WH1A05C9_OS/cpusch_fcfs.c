#include<stdio.h>

void sort(int pro[],int ari[],int bru[],int n){
	printf("before sorting\n");
	for(int i=0;i<n;i++){
		printf("%d ",ari[i]);
	}
	for(int a=0;a<n-1;a++){
		for(int b=a;b<n-1;b++){
			if(ari[b]>ari[b+1]){
				int temp=ari[b];
				ari[b]=ari[b+1];
				ari[b+1]=temp;
				int  c=pro[b];
				pro[b]=pro[b+1];
				pro[b+1]=c;
				int t=bru[b];
				bru[b]=bru[b+1];
				bru[b+1]=t;
			}
		}
	}
	printf("\n");
	printf("after printing\n");
	for(int d=0;d<n;d++){
		printf("%d ",ari[d]);
	}
	printf("\n");
}

void avg(int bru[],int ari[],int n){
	int gann[n];
	int sum=0;
	for(int e=0;e<n;e++){
		sum+=bru[e];
		gann[e]=sum;
	}
	int sumofavg=0;
	int avgwaiting=0;
	int turn[n];
	int prev=0;
	for(int l=0;l<n;l++){
		sumofavg+=gann[l]-ari[l];
		turn[l]=sumofavg-prev;
		prev=sumofavg;
		//avgwaiting+=(gann[l]-ari[l])-bru[l];
	}
	for(int m=0;m<n;m++){
	    int j=turn[m]-bru[m];
	    if((j)<0){
		    j=0;
	    }
	    avgwaiting+=j;
		//printf("%d\n",avgwaiting);
	}
	//return sumofavg;
	avgwaiting=avgwaiting/n;
	sumofavg=sumofavg/n;
	printf("%d\n",sumofavg);
        printf(" average waiting time :\n");
	printf("%d",avgwaiting);

}

int main(){
	int n;
	printf("enter the number of processes :");
	scanf("%d",&n);
	
	if (n <= 0) {
        printf("Number of processes must be greater than zero.\n");
        return 0;
    }

	int pro[n],ch;
	int ari[n],bru[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&pro[i]);
	}
	
	printf("enter the arrival times\n");
	for(int j=0;j<n;j++){
		scanf("%d",&ari[j]);
	}
	
	printf("enter the brust times\n");
	for(int k=0;k<n;k++){
		scanf("%d",&bru[k]);
	}
	
	//checking valid or not
	for (int i = 0; i < n; i++) {
        if (pro[i] < 0 || ari[i] < 0 || bru[i] < 0) {
            printf("Invalid input: process ID, arrival time, and burst time must be non-negative.\n");
            return 0;
        }
    }


	// sorting
	sort(pro,ari,bru,n);

	//average of turn time
	printf("average turn time: \n");
	avg(bru,ari,n);

}









