#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>/*his includes the POSIX threads library. This is essential for multi-threading support (pthread_create, pthread_join, pthread_mutex_lock, etc.)*/
#include<semaphore.h>   /*Synchronization between producer and consumer*/
#define MAX_BUFFER_SIZE 10 //maximum buffer size


int buffer[MAX_BUFFER_SIZE];
int in=0;
int out=0;

sem_t empty; /*semaphore for empty slots*/
sem_t full;  /*semaphore for filled slots*/
pthread_mutex_t mutex;   /*mutual exclusive access*/

/*function for producer*/
void *producer(void *param)
{
int item;

	while(1)
	{
	  printf("Enter the item to be produced:");
	  scanf("%d",&item);
	  sem_wait(&empty);  /*if the buffer is full then we wait*/
	  pthread_mutex_lock(&mutex); /*lock for buffer for exclusive access*/

	  /*producing an item and inserting it into the buffer*/
	  buffer[in]=item;
	  in=(in+1)%MAX_BUFFER_SIZE;
	  printf("Produced item: %d\n",&item);

	  pthread_mutex_unlock(&mutex); /*unlocking the buffer*/

	  sem_post(&full);  /*signal that there is a full slot in buffer*/
	}	
	return NULL;
}	

/*function for consumer*/
void *consumer(void *param)
{
int item;
	
	while(1)
	{
	  sem_wait(&full); /*we wait if the buffer is empty*/
	  pthread_mutex_lock(&mutex);  /*lock buffer for exclusive access*/

	  /*consuming items from buffer*/
	  item=buffer[out];
	  out= (out+1)%MAX_BUFFER_SIZE;
	  printf("Consumed item %d\n",&item);

	  pthread_mutex_unlock(&mutex); /*unlock buffer*/

	  sem_post(&empty);  /*signal that there is empty slot in buffer*/
	}	
	return NULL;
}	
int main()
{
int n_producers,n_consumers;
sem_init(&empty,0,MAX_BUFFER_SIZE);  /*at first all buffer slots are empty*/
sem_init(&full,0,0);	/*there are no slots which are full*/
pthread_mutex_init(&mutex,NULL);  /*initializing mutex for mutual exclusion*/

printf("\nEnter no.of producers:");
scanf("%d",&n_producers);
printf("\nEnter no.of consumers:");
scanf("%d",&n_consumers);
pthread_t producer[n_producers], consumer[n_consumers];

    // Creating producer threads
    for (int i = 0; i < n_producers; i++) {
        pthread_create(&producer[i], NULL, producer, NULL);
    }

    // Creating consumer threads
    for (int i = 0; i < n_consumers; i++) {
        pthread_create(&consumer[i], NULL, consumer, NULL);
    }

    // Join producer threads
    for (int i = 0; i < n_producers; i++) {
        pthread_join(producer[i], NULL);
    }

    // Join consumer threads
    for (int i = 0; i < n_consumers; i++) {
        pthread_join(consumer[i], NULL);
    }

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}	

