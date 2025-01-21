#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("process not created");
		return 1;
	}
	else if(pid == 0)
	{
		printf("chid process is created with (pid:%d)\n",getpid());
		execl("./g3","./g3",NULL);  //here g3 is name of the executable file of fcfs file
		//execl("me","me",NULL);
		//execl("/bin/ls","ls",NULL);
		perror("error");
		return 1;
	}
	else 
	{
		printf("parent process is created with (pid:%d)\n",getpid());
		int status;
		wait(&status);
		if(WIFEXITED(status))
		{
			printf("\nchild process ended with status: %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("not exited properly");
		}
		printf("parent process ended\n");
	}
	return 0;
}
