#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int np, nr;
    printf("Enter the number of processes and number of resources: ");
    scanf("%d %d", &np, &nr);

    int proc[np], res[nr], seq[np], all[np][nr], max[np][nr], need[np][nr], avail[nr];
    bool finished[np]; 

    
    printf("Enter the process IDs: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &proc[i]);
    }

    
    printf("Enter the resource IDs: ");
    for (int i = 0; i < nr; i++) {
        scanf("%d", &res[i]);
    }

    
    printf("Enter the resources allocated to each process: \n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    
    printf("Enter the maximum resources needed by each process: \n");
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    
    printf("Enter the available resources: ");
    for (int i = 0; i < nr; i++) {
        scanf("%d", &avail[i]);
    }

    
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }

    
    for (int i = 0; i < np; i++) {
        finished[i] = false;
    }

    int safeindex = 0;  
    int count = 0;      
    while(count < np){
	    bool found = false;
	    for(int i=0;i<np;i++){
		    if(!finished[i]){
		   	 bool canfinish = true;
			 for(int j=0;j<nr;j++){
				 if(need[i][j]>avail[j]){
					 canfinish=false;break;
				 }
			 }
			if(canfinish){
				printf("\nBefore granting the request to process %d the available resources are:\n ",proc[i]);
				for(int k=0;k<nr;k++) printf("%d\t",avail[k]);
				printf("\nAfter granting the request to process %d the available resources are:\n ",proc[i]);
				for(int j=0;j<nr;j++){
					avail[j]+=all[i][j];
					printf("%d\t",avail[j]);
				}
				
				finished[i] = true;
				count++;
				seq[safeindex++] = proc[i];
				found = true;
		    	}
		   }
	    }
	    if(!found){
		    printf("The system is in unsafe state.\n");
		    return 0;
	    }
    }


    printf("\nThe safe sequence is: ");
    for (int i = 0; i < np; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");

    return 0;
}








/*
  OUTPUT:-
  Enter the number of processes and number of resources: 5 3
Enter the process IDs: 1 2 3 4 5
Enter the resource IDs: 1 2 3
Enter the resources allocated to each process:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the maximum resources needed by each process:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter the available resources: 3 3 2

Before granting the request to process 2 the available resources are:
 3      3       2
After granting the request to process 2 the available resources are:
 5      3       2
Before granting the request to process 4 the available resources are:
 5      3       2
After granting the request to process 4 the available resources are:
 7      4       3
Before granting the request to process 5 the available resources are:
 7      4       3
After granting the request to process 5 the available resources are:
 7      4       5
Before granting the request to process 1 the available resources are:
 7      4       5
After granting the request to process 1 the available resources are:
 7      5       5
Before granting the request to process 3 the available resources are:
 7      5       5
After granting the request to process 3 the available resources are:
 10     5       7
The safe sequence is: 2 4 5 1 3

  */


