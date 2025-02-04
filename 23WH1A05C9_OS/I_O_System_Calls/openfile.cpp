#include<stdio.h>
//#include<stdlib.h> // for exit 
#include<unistd.h> // contains fun of read(),write(),close()
#include<fcntl.h> //contains the flags like ex:o_rdonly
#include<errno.h>
int main(){
	
	int fd=open("example.txt",O_RDONLY | O_CREAT);
	
	printf("fd=%d\n",fd);
	
	if(fd==-1){
		printf("Error number %d \n",errno);
		perror("program");
	}
	return 0;
	
	
}


