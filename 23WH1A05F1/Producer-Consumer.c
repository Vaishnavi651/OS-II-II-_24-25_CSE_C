#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty, x = 0;

void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nProducer produces item %d\n", x);
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nConsumer consumes item %d\n", x);
    x--;
    ++mutex;
}

int main()
{
    int n, i;

    printf("Enter the size of the buffer: ");
    scanf("%d", &empty);

    for (i = 1; i > 0; i++) {

        printf("\n1. Press 1 for Producer"
                "\n2. Press 2 for Consumer"
                "\n3. Press 3 for Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            if ((mutex == 1) && (empty != 0)) {
                producer();
            } else {
                printf("\nBuffer is full!\n");
            }
            break;

        case 2:
            if ((mutex == 1) && (full != 0)) {
                consumer();
            } else {
                printf("\nBuffer is empty!\n");
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice! Please select 1, 2, or 3.");
        }
    }

    return 0;
}
