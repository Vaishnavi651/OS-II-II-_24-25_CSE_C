#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int fd;
	char buf[100];
	fd=open("f1.txt",O_WRONLY|O_CREAT,0644);
	if(fd==-1){
		perror("Error occured\n");
		return 1;
	}
	write(fd,"Hello\n",6);
	close(fd);
	fd=open("f1.txt",O_RDONLY,0644);
	if(fd==-1){
		perror("Error occured\n");
	}
	read(fd,buf,sizeof(buf));
	printf("Read from file: %s",buf);
	close(fd);
/*#FFFFFF	off_t off=lseek(fd,0,SEEK_SET);
if(off==(off_t-1)){
		perror("Error seeking");
		return 1;
	}*/
	struct stat fs;
	if(stat("f1.txt",&fs)==-1){
		perror("Error");
	}
	printf("FIle size:%lld bytes\n",(long long)fs.st_size);
	DIR *dir;
	struct dirent *enty;
	dir=opendir(".");
	if(dir==NULL){
		perror("Error opening\n");
		return 1;
		}
	printf("Directory contents are:\n");
	while((enty=readdir(dir))!=NULL){
		printf("%s\n",enty->d_name);
	}
	closedir(dir);
	return 0;
}



