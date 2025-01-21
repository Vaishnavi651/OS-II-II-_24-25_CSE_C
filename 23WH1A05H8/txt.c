#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) { 
        printf( "no child created\n");
        exit(-1);
    } else if (pid == 0) { 
        execlp("/bin/ls", "ls", NULL);
       
        printf( "execlp Failed\n");
        exit(-1);
    } else { 
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
