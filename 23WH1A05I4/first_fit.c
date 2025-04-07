#include<stdio.h>
int main(){
	int memory_size,num_blocks,num_processes;
	int block_size[10],process_size[10],allocation[10];
	printf("enter the size of the memory:");
	scanf("%d",&memory_size);
	printf("enter the number of memory blocks: ");
	scanf("%d",&num_blocks);
	for(int i=0;i<num_blocks;i++){
	printf("size of the memory blocks %d: ",i+1);
	scanf("%d",&block_size[i]);
	}
	printf("enter the number of processe:");
	scanf("%d",&num_processes);
	for(int i=0;i<num_processes;i++){
	printf("enter the size of the processes %d:",i+1);
	scanf("%d",&process_size[i]);
	allocation[i]=-1;
	}
	for(int i=0;i<num_processes;i++){
		for(int j=0;j<num_blocks;j++){
			if(block_size[j]>=process_size[i]){
			allocation[i]=j;
			block_size[j]-=process_size[i];
			break;
			}
		}
	}
	printf("\n process No.\t process size\t block No.\n");
	for(int i=0;i<num_processes;i++){
		if(allocation[i]!=-1){
			printf("%d\t\t%d\t\t%d\n",i+1,process_size[i],allocation[i]+1);
			}
		else{
		printf("%d\t\t%d\t\t Not allocated\n",i+1,process_size[i]);
		}
	}
	return 0;
	}
	
	
	

