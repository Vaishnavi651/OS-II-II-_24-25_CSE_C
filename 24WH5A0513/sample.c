#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
printf("I am before fork\n");
fork();
printf("I am after first fork\n");
fork();
printf("Iam after second fork\n");
fork();
printf("my process id:%d\n",getpid());
printf("I am final fork\n");
return 0;
}

