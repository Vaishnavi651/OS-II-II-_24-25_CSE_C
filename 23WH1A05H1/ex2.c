#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
        printf("my process 2:%d\n",getpid());
        printf("process 2:\n");
        return 0;
}
