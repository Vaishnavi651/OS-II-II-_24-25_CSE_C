#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int mutex = 1;     
int full = 0;      
int empty;         
int x = 0;         

void producer()
{    
    --mutex;
    ++full;   
    --empty;
    x++;
    printf("\nProducer produces  the item %d", x);
    printf("\nBuffer Status: %d full, %d empty", full, empty);
    ++mutex;
}

void consumer()
{   
    --mutex;   
    --full;
    ++empty;
    printf("\nConsumer consumes  the item %d", x);
    printf("\nBuffer Status: %d full, %d empty", full, empty);
    x--;
    ++mutex;
}

int main()
{
    int n, i;
    
    
    printf("Enter buffer size: ");
    scanf("%d", &empty);

    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
    
    for (i = 1; i > 0; i++) {
        printf("\n\nEnter your choice: ");
        scanf("%d", &n);
        switch (n) {
        case 1:                           
            if ((mutex == 1) && (empty != 0)) {
                producer();
            }
            else {
                printf("\nBuffer is full! Can't produce.");
                printf("\nBuffer Status: %d full, %d empty", full, empty);
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0)) {
                consumer();
            }
            else {
                printf("\nBuffer is empty! Can't consume.");
                printf("\nBuffer Status: %d full, %d empty", full, empty);
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n Not valid ! Try again.");
        }
    }
}
