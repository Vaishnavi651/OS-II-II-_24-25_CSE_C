#include<stdio.h>
#include<stdlib.h>

struct p {
    int id;
    int at;
    int bt;
    int ct;
    int wt;
    int tt;
}; 

int compare(const void *a, const void *b) {
    struct p *p1 = (struct p *)a;
    struct p *p2 = (struct p *)b;
    if(p1->at == p2->at) {
        return p1->bt - p2->bt;
    }
    return p1->at - p2->at;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct p pr[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter process id: ");
        scanf("%d", &pr[i].id);
        printf("Enter arrival time: ");
        scanf("%d", &pr[i].at);
        printf("Enter burst time: ");
        scanf("%d", &pr[i].bt);
    }

    qsort(pr, n, sizeof(struct p), compare);  // Corrected function call here

    pr[0].wt = 0;
    pr[0].ct = pr[0].bt + pr[0].at;
    pr[0].tt = pr[0].ct - pr[0].at;

    for(int i = 1; i < n; i++) {
        pr[i].wt = pr[i-1].ct - pr[i].at;
        if(pr[i].wt < 0) pr[i].wt = 0; 
        pr[i].ct = pr[i].wt + pr[i].bt + pr[i].at;
        pr[i].tt = pr[i].ct - pr[i].at;
    }

    float avgwt = 0.0, avgtt = 0.0;
    for(int i = 0; i < n; i++) {
        avgwt += pr[i].wt;
        avgtt += pr[i].tt;
    }

    avgwt /= n;
    avgtt /= n;

    printf("\nProcess | Burst Time | Arrival Time | Waiting Time | Turnaround Time | Completion Time\n");
    for(int i = 0; i < n; i++) {
        printf("   %d    |    %d       |      %d      |      %d       |       %d        |      %d\n", 
               pr[i].id, pr[i].bt, pr[i].at, pr[i].wt, pr[i].tt, pr[i].ct);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt);
    
    printf("\nGantt Chart\n");
    printf("  |");
    for(int i = 0; i < n; i++) {
        printf(" P%d |", pr[i].id);
    }
    printf("\n");

    printf("  |");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < pr[i].bt; j++) {
            printf("---");
        }
        printf("|");
    }
    printf("\n");

    printf("  0");
    for(int i = 0; i < n; i++) {
        printf("   %d", pr[i].ct);
    }
    printf("\n");

    return 0;
}

