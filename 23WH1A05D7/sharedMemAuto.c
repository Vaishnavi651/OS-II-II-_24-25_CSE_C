#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>

int main()

{

	int i; // iterative variable
	void *shared_memory;// Shared Memory 
	char buff[100]; // Buffer Array
	int shmid;// shmid = Shared Memory Id
	
	shmid=shmget((key_t)2345, 1024, 0666); // shmget = Shared Memory Get
	
	printf("Key of shared memory is %d\n",shmid);
	
	shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
	
	printf("Process attached at %p\n",shared_memory);
	
	printf("Data read from shared memory is : %s\n",(char *)shared_memory);


}
