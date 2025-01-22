#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		printf("Fork Failed");
		exit(-1);
           }
	else if(pid==0)
	{
		execlp("who","who","-l",NULL);
             }
	else{
	wait(NULL);
	printf("Parent Process PID =%d\n",getpid());
	printf("Child process created with PID = %d\n",pid);
	printf("Child Complete");
	exit(0);
        }
}
