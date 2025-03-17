#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefds[2];
    int returnstatus;
    char userMessage[100];

    returnstatus = pipe(pipefds);

    if (returnstatus == -1) {
        printf("Unable to create the pipe.\n");
        return 1;
    }

    printf("Sender started.\n");

    while (1) {
        printf("\n[Sender] Enter your message: ");
        fgets(userMessage, sizeof(userMessage), stdin);

        userMessage[strcspn(userMessage, "\n")] = '\0'; // Remove newline character

        if (strcmp(userMessage, "exit") == 0) {
            printf("\n[Sender] Ending the chat. Goodbye!\n");
            break;
        }

        write(pipefds[1], userMessage, sizeof(userMessage));
        printf("[Sender] Sent message: \"%s\"\n", userMessage);
    }

    return 0;
}
