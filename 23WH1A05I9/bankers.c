#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int inst[m];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the instances for the resource:");
    for(i=0;i<m;i++)
    {
	    scanf("%d",&inst[i]);
    }


    int alloc[n][m], max[n][m], avail[m];

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    int allsum[m];
    for (i = 0; i < m; i++)
    {
	allsum[i]=0;
        for(j=0;j<n;j++)
	{
		allsum[i]+=alloc[j][i];
	}
	avail[i]=inst[i]-allsum[i];
    }
    printf("Available are:");
    for(i=0;i<m;i++)
    {
	    printf("%d ",avail[i]);
     }
     printf("\n");
    int f[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) {
        f[k] = 0;  
    }

    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) { 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) { 
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) { 
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y]; 
                    }
                    f[i] = 1; 
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The following system is not safe\n");
            break;
        }
    }

    if (flag == 1) {
	printf("System is in safe condition.\n Following is the correct sequence to avoid deadlock");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);
    }
    printf("\n");

    return 0;
}


