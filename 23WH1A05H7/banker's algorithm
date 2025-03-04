#include <stdio.h>
#include <stdbool.h>

int main() {
    int p, r, count = 0, i, j;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    int allocation[p][r], max[p][r], need[p][r], available[r], safe[p], finish[p];
    int completed = 0;

    printf("Enter allocation matrix: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter max matrix: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &available[i]);
    }
    
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for (i = 0; i < p; i++) {
        finish[i] = 0;
    }

    printf("Need matrix: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    
    while (count < p) {
        bool found = false;
        for (i = 0; i < p; i++) {
            if (finish[i] == 0) {
                bool canAllocate = true;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > available[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    safe[count++] = i;
                    for (j = 0; j < r; j++) {
                        available[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("The system is in unsafe state.\n");
            return 1;
        }
    }

    printf("\nThe system is in safe state.\nSafe sequence: ");
    for (i = 0; i < p; i++) {
        printf("P%d", safe[i]);
        if (i < p - 1) printf(" -> ");
    }
    printf("\n");

    return 0;
}
