#include<stdio.h>
int main(){
	int n;
	int r;
	int ins[r];
	printf("ENter no of processes:");
	scanf("%d",&n);
	printf("enter no of resources");
	scanf("%d",&r);
	printf("ENter instances for the resources:");
	for(int i=0;i<r;i++){
		scanf("%d",&ins[i]);
	}
	int allo[n][r];
	int max[n][r];
	for(int i=0;i<n;i++){
		for(int j=0;j<r;j++){
			scanf("%d",&allo[i][j]);
		}
	}
	printf("Enter max resources for each process");
       for(int i=0;i<n;i++){

       		for(int j=0;j<r;j++){
			scanf("%d",&max[i][j]);
      		 }
     
       }
       for(int i=0;i<n;i++){
	       for(int j=0;j<r;j++){
		       printf("%d",allo[i][j]);
	       }
	       printf("\n");
       }
       int need[n][r];
       for(int i=0;i<n;i++){
	       for(int j=0;j<r;j++){
		       need[i][j]=max[i][j]-allo[i][j];
	       }
	       
	}
       int sum[r];
       for(int i=0;i<r;i++){
	       sum[i]=0;
       }
       for(int j=0;j<r;j++){
	       for(int i=0;i<n;i++){
			sum[j]+=allo[i][j];
	       }
       }
       int avail[r];
	       for(int j=0;j<r;j++){
		       avail[j]=ins[j]-sum[j];
       }
      int work[r];
     for(int i=0;i<r;i++){
	    work[i]=avail[i];
     }
     int fini[n];
     int seq[n];
     int c=0;
     for(int i=0;i<n;i++){
	     fini[i]=0;
	     seq[i]=0;
     }
     int k=0;`
     while(c<n){
	     int found=0;
	     printf("HEre process started execution\n");
			
   		 for(int i=0;i<n;i++){
 
    			if(fini[i]==0){	 
				int canexe=1;	
	   			for(int j=0;j<r;j++){
		  			if(need[i][j]>work[j]){
						canexe=0;
						break;
		  			}

	  			 }		

	   			if(canexe==1){
		   			for(int j=0;j<r;j++){
			   			work[j]+=allo[i][j];
		  			 }
		  			 c++;
		   			fini[i]=1;
		   			found=1;
		   			seq[k++]=i;
		   			break;
				}
	  
		       	}
   		 }
		 if(!found){
			 printf("system is in unsafe state\n");
			 return -1;
		 }
    }
     printf("SYstem is in safe state\n");
     for(int i=0;i<n;i++){
    printf("order is %d",seq[i]);
    }
   
    
     }	
