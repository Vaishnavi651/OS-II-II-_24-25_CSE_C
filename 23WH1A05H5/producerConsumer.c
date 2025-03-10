#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define max 10

int bs;

int *buffer;
int in=0;
int out=0;
int pc=0;
int cc=0;
sem_t mutex;
sem_t full;
sem_t empty;

void *producer(void* args){
	int item=1;
	while(pc<max){
		sem_wait(&empty);
		sem_wait(&mutex);
		buffer[in]=item;
		printf("Producer produced: %d\n",item);
		item++;
		in=(in+1)%bs;
		pc++;
		sem_post(&mutex);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void* args){
	while(cc<max){
		sem_wait(&full);
		sem_wait(&mutex);
		int item = buffer[out];
		printf("Consumer consumed: %d\n",item);
		out = (out+1)%bs;
		cc++;
		sem_post(&mutex);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

int main(){
	printf("Enter buffer size\n");
	scanf("%d",&bs);
	buffer=(int*)malloc(bs * sizeof(int));
	if(buffer==NULL){
    		printf("Memory allocation failed\n");
    		return 1;
	}

	pthread_t pt, ct;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,bs);
	
	pthread_create(&pt,NULL,producer,NULL);
	pthread_create(&ct,NULL,consumer,NULL);

	pthread_join(pt,NULL);
	pthread_join(ct,NULL);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);

	return 0;
}
