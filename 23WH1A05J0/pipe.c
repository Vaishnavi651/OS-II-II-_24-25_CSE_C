#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char buffer[100];
	int fd[2];
	if(pipe(fd) == -1)
	{
		perror("Pipe failed\n");
		return 1;
	}
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("Fork failed");
		return 1;
	}
	else if(pid == 0)
	{
		close(fd[1]);
		read(fd[0],buffer,sizeof(buffer));
		printf("Child received : %s ",buffer);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		char msg[] = "Hello from BVRIT";
		write(fd[1],msg,strlen(msg)+1);
		close(fd[1]);
	}
	return 0;
}
