#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
int fd[2];
char buffer[100];
if(pipe(fd)==-1)
{
perror("pipe failed");
return 1;
}
pid_t pid=fork();
if(pid<0)
{
perror("fork failed");
return 1;
}
else if(pid==0)
{
close(fd[1]);read(fd[0],buffer,sizeof(buffer));
printf("Child received:%s\n",buffer);
close(fd[0]);
}
else{
close(fd[0]);
char msg[]="Hello from parent";
write(fd[1],msg,strlen(msg)+1);
close(fd[1]);
}
return 0;
}
