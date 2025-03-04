#include<stdio.h>

int main() {
    int p, c, count = 0, i, j, terminate = 0;
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &c);
    
    int alc[p][c],max[p][c],need [p][c],safe[p],available[c],instances[c],done[p];

    printf("Enter the number of instances for each resource: \n");
    for (i = 0; i < c; i++) {
        scanf("%d", &instances[i]);
    }
    
    printf("Enter allocation matrix (%dx%d):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &alc[i][j]);
        }
    }
    
    printf("Enter the maximum resource requirement matrix (%dx%d):\n", p, c);
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    for (j = 0; j < c; j++) {
        available[j] = instances[j];
        for (i = 0; i < p; i++) {
            available[j] -= alc[i][j];
        }
    }
    
    printf("\nNeed resources matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < c; j++) {
            need[i][j] = max[i][j] - alc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < p; i++) {
        done[i] = 0;
    }
    
    while (count < p) {
        for (i = 0; i < p; i++) {
            if (done[i] == 0) {
                safe[count] = i;
                done[i] = 1;
                printf("\nProcess P%d is executing...\n", i);
                printf("Need Resources of P%d:\n",i);
                for(int j=0;j<c;j++){
                        printf("%d\t",need[i][j]);
                }

                printf("\nAvailable resources before Completion of P%d:\n",i);
                for( j=0;j<c;j++){
                        printf("%d\t",available[j]);
                }

                for (j = 0; j < c; j++) {
                    available[j] += alc[i][j];
                }

                printf("\nAvailable resources after completion of P%d:\n", i);
                for (j = 0; j < c; j++) {
                    printf("%d\t", available[j]);
                }
                printf("\n");

                count++;
                terminate = 0;
                } else {
                    terminate++;
                }
            }
        }
        if (terminate == (p - 1)) {
            printf("Safe sequence does not exist\n");
            break;
        }
    }
    
    if (terminate != (p - 1)) {
        printf("\nAvailable resources after completion:\n");
        for (i = 0; i < c; i++) {
            printf("%d\t", available[i]);
        }
        printf("\nSafe sequence:\n");
        for (i = 0; i < p; i++) {
            printf("P%d\t", safe[i]);
        }
    }
    
    return 0;
}

