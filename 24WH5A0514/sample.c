#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
printf("i am before fork\n");
fork();
printf("i am after 1st fork\n");
fork();
printf("i am after 2nd fork\n");
fork();
printf("my process id:%d\n",getpid());
printf("I am at final fork");
return 0;
}
