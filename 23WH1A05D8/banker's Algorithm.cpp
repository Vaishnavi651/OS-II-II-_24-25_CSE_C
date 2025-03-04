#include <stdio.h>
#include <conio.h>

int main() {
    int k = 0, a = 0, b = 0, instance[5], availability[5], allocated[10][5], need[10][5], MAX[10][5], process, P[10], no_of_resources, cnt = 0, i, j, op[5];
    int finished[10] = {0};  // Array to track if a process has finished

    printf("\n Enter the number of resources : ");
    scanf("%d", &no_of_resources);
    
    printf("\n enter the max instances of each resources\n");
    for (i = 0; i < no_of_resources; i++) {
        availability[i] = 0;
        printf("%c= ", (i + 97));
        scanf("%d", &instance[i]);
    }

    printf("\n Enter the number of processes : ");
    scanf("%d", &process);

    printf("\n Enter the allocation matrix \n     ");
    for (i = 0; i < no_of_resources; i++)
        printf(" %c", (i + 97));
    printf("\n");

    for (i = 0; i < process; i++) {
        P[i] = i;
        printf("P[%d]  ", P[i]);
        for (j = 0; j < no_of_resources; j++) {
            scanf("%d", &allocated[i][j]);
            availability[j] += allocated[i][j];
        }
    }

    printf("\nEnter the MAX matrix \n     ");
    for (i = 0; i < no_of_resources; i++) {
        printf(" %c", (i + 97));
        availability[i] = instance[i] - availability[i];
    }
    printf("\n");

    for (i = 0; i < process; i++) {
        printf("P[%d]  ", i);
        for (j = 0; j < no_of_resources; j++)
            scanf("%d", &MAX[i][j]);
    }

    // Safety check and finding the safe sequence
    int finished_processes = 0;

    while (finished_processes < process) {
        int progress_made = 0;  // To track if any process was able to finish in this iteration
        
        for (i = 0; i < process; i++) {
            if (!finished[i]) {  // Check only unfinished processes
                cnt = 0;
                b = P[i];
                
                // Calculate the need matrix
                for (j = 0; j < no_of_resources; j++) {
                    need[b][j] = MAX[b][j] - allocated[b][j];
                    if (need[b][j] <= availability[j])  // Check if the process's needs can be satisfied
                        cnt++;
                }

                if (cnt == no_of_resources) {  // All needs can be satisfied
                    op[k++] = P[i];  // Add process to safe sequence
                    finished[i] = 1;  // Mark process as finished
                    finished_processes++;

                    // Release allocated resources
                    for (j = 0; j < no_of_resources; j++)
                        availability[j] += allocated[b][j];
                    
                    progress_made = 1;  // Indicate that progress was made in this iteration
                }
            }
        }

        // If no progress was made, it indicates a deadlock
        if (!progress_made) {
            printf("\nNot Safe (Deadlock detected)\n");
            return 0;
        }
    }

    // If all processes are finished and we have a safe sequence
    printf("\nSafe state\n");
    printf("Safe sequence: <");
    
    for (i = 0; i < k; i++) {
        printf(" P[%d] ", op[i]);
    }
    printf(">\n");

    getch();
    return 0;
}

