#include<stdio.h>
#include<unistd.h>
#define BUFFER_SIZE 10
int mutex = 1;

int full = 0;

int empty = 10, x = 0;

void wait(int *S) {
    while (*S <= 0); 
    (*S)--;
}
void signal(int *S){
	(*S)++;
}
void prod(){
	wait(&empty);
	wait(&mutex);
	x-=1;
	printf("Producer produces item:%d",x);
	signal(&mutex);
	signal(&full);

}
void consu(){
	do{
		wait(&full);
		wait(&mutex);

		printf("\nCOnsumer consumes an item :%d",x);
		x-=1;

		signal(&mutex);
		signal(&empty);
		sleep(1);
	}while(x>0);
}
int main(){
	for(int i=0;i<10;i++){
		prod();
		sleep(1);
		consu();
	}
	return 0;
}
