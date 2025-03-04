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

