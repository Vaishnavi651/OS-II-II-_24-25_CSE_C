#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int p, int r, int max[p][r], int all[p][r], int need[p][r]) {
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }
}

bool isSafe(int p, int r, int avail[r], int all[p][r], int need[p][r]) {
    int work[r];
    bool finish[p];
    int safes[p], index = 0;

    for (int i = 0; i < p; i++) 
        finish[i] = false;
    
    for (int i = 0; i < r; i++) 
        work[i] = avail[i];
    printf("avialable resources ");
         for(int i=0;i<r;i++)
              printf(" %d ",work[i]);
          printf("\n");

    while (true) {
        bool f = false;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < r; j++)
                        work[j] += all[i][j];

                    finish[i] = true;
                    safes[index++] = i;
                    f = true;
		    printf("processs %d executed new Avialable",i);
		    for(int i=0;i<r;i++)
			    printf(" %d ",work[i]);
		    printf("\n");
                }
            }
        }
        if (!f) 
            break;
    }

    for (int i = 0; i < p; i++) {
        if (!finish[i]) {
            printf("System is NOT in a safe state!\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence: ");
    for (int i = 0; i < p; i++)
        printf("P%d ", safes[i]);
    printf("\n");

    return true;
}

int main() {
    int r, p;
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    printf("Enter the number of processes: ");
    scanf("%d", &p);

    int total[r];
    printf("Enter total instances for each resource: ");
    for (int i = 0; i < r; i++) {
        scanf("%d", &total[i]);
    }

    int all[p][r], max[p][r];
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter max matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    int avail[r];
    for (int j = 0; j < r; j++) {
        int sum = 0;
        for (int i = 0; i < p; i++)
            sum += all[i][j];
        avail[j] = total[j] - sum;
    }

    int need[p][r];
    calculateNeed(p, r, max, all, need);
    isSafe(p, r, avail, all, need);

    return 0;
}

