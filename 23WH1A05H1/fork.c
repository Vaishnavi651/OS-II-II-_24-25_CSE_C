#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	printf("my process :%d\n",getpid());
	execv("./ex2","NULL");
	return 0;
}
