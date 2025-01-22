#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
pid_t pid=fork();
if(pid<0){
printf("fork failed");
return 1;
}

else if(pid == 0){
printf("Child process is (PID:%d) executing the command\n",getpid());
execlp("ls","ls",NULL);
perror("EXecution is failed");
}
else{
printf("Parent process is executing (PID:%d)\n",getpid());
int status;
wait(&status);
printf("Child process is executed\n");
}
return 0;

}
