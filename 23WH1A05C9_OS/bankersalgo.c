#include<stdio.h>

int main()
{
	//inputs of no of processes,no of resources,instances of each resource,allocation matrix and maximum matrix
	int n,r;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("enter the number of resources : ");
	scanf("%d",&r);

	int all[n][r],max[n][r],ins[r],ava[r];

	printf("enter the instances of each resource :");
	for(int i=0;i<r;i++)
	{
		scanf("%d",&ins[i]);
	}




	printf(" enter the allocation matrix of n X r : ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d",&all[i][j]);
		}
	}



	printf(" enter the maximum matrix of n X r : ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}


       printf("Available resources are :");
       int sum=0;
       for(int i=0;i<r;i++)
       {
	       sum=0;
	       for(int j=0;j<n;j++)
	       {
		       sum+=all[j][i];
	       }
	       ava[i]=ins[i]-sum;
	       printf("%d ",ava[i]);
       }




       //calculation of needed matrix
       int need[n][r];
       for(int i=0;i<n;i++)
       {
	       for(int j=0;j<r;j++)
	       {
		       need[i][j]=max[i][j]-all[i][j];
	       }
       }


       printf("\nPro\tAllo\tMax\tNeed\tAvai\n");
    for ( int i = 0; i < n; i++) {
        printf("P%d\t", i); // Print process number

        // Print Allocation for process i
        for (int j = 0; j < r; j++) {
            printf("%d ", all[i][j]);
        }
        printf("\t");

        // Print Maximum for process i
        for (int j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");

	// Print Need for process i
        for (int j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
	printf("\t");

	
        // Print Available resources
        if (i == 0) {
            for (int j = 0; j < r; j++) {
                printf("%d ", ava[j]);
            }
            printf("\t");
        }

       printf("\n");
    
     }




    //Bankers algorithm main logic
    
    // f is for checking
    int f[n],ans[n],idx=0;


    for(int i=0;i<n;i++)
    {
	    f[i]=0;
    }

    
    for(int a=0;a<n;a++){
    for(int i=0;i<n;i++)
    {
	    
	    if(f[i]==0)
	    {
		    int flag=0;
	    	for(int j=0;j<r;j++)
	    	{
		    if(ava[j]<need[i][j]){
			    flag=1;
			    break;
		    }
	    	}
	    

	    if(flag==0)
	    {
		    printf("\nbefore the available resources :");
		    for(int b=0;b<r;b++)
		    {
			    printf("%d ",ava[b]);
		    }

		    ans[idx++]=i;
		    for(int k=0;k<r;k++)
		    {
			    ava[k]+=all[i][k];
		    }
		    f[i]=1;
		    printf("\np%d reached safe state ",i);
		    printf("\nnow the available resources are :");
		    for(int c=0;c<r;c++)
		    {
			    printf("%d ",ava[c]);
		    }
		    printf("\n");
	    }
	    }
    }
    }



    //checking of safe state or not 

    int temp=0;

    for(int i=0;i<n;i++)
    {
	    if(f[i]==0){
		    temp=1;
		    printf("DEADLOCK occurred");
		    break;
	    }
    }


    if(temp==0)
    {
	    printf("\nThe safe sequence is : ");

	    for(int i=0;i<n-1;i++)
	    {
		    printf("p%d->",ans[i]);
	    }
	    printf("p%d",ans[n-1]);
    }

    return 0;


}
