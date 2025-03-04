
Conversation opened. 1 unread message. 

Skip to content
Using BVRITHYDERABAD Mail with screen readers

14 of 1,020
Fwd:
Inbox

TANVI MANDAS
Attachments
10:58 AM (11 hours ago)
to me



---------- Forwarded message ---------
From: SAI KRUSHINI LINGALA <24wh5a0513@bvrithyderabad.edu.in>
Date: Tue, Mar 4, 2025 at 10:54 AM
Subject:
To: <24wh5a0517@bvrithyderabad.edu.in>




 One attachment
  •  Scanned by Gmail
#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int nProcesses, nResources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];

void calculateNeed() {
    for (int i = 0; i < nProcesses; i++) {
        for (int j = 0; j < nResources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finish[MAX_PROCESSES] = { false };
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    
    for (int i = 0; i < nResources; i++) {
        work[i] = available[i];
    }

    while (count < nProcesses) {
        bool found = false;
        for (int p = 0; p < nProcesses; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int j = 0; j < nResources; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    
                    for (int j = 0; j < nResources; j++) {
                        work[j] += allocation[p][j];
                    }
                    safeSequence[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < nProcesses; i++) {
        printf("%d ", safeSequence[i]);
    }
    printf("\n");
    return true;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &nProcesses);
    printf("Enter number of resources: ");
    scanf("%d", &nResources);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < nProcesses; i++) {
        for (int j = 0; j < nResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < nProcesses; i++) {
        for (int j = 0; j < nResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter available resources:\n");
    for (int i = 0; i < nResources; i++) {
        scanf("%d", &available[i]);
    }

    
    calculateNeed();

    
    isSafe();

    return 0;
}
bankers.c
Displaying bankers.c.
