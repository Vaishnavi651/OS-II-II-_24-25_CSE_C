#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefds[2];
    int returnstatus;
    char pipeMessage[100];

    returnstatus = pipe(pipefds);

    if (returnstatus == -1) {
        printf("Unable to create the pipe.\n");
        return 1;
    }

    printf("Receiver started.\n");

    while (1) {
        read(pipefds[0], pipeMessage, sizeof(pipeMessage));
        printf("[Receiver] Received message: \"%s\"\n", pipeMessage);

        if (strcmp(pipeMessage, "exit") == 0) {
            printf("[Receiver] Ending the chat.\n");
            break;
        }

        printf("[Receiver] Replying: 'Got your message!'\n");
        write(pipefds[1], "Got your message!", sizeof("Got your message!"));
    }

    return 0;
}
