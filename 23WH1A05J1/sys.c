#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(){
	char buffer[100];
	ssize_t bytes;
	
	int fd = open("honey.txt",O_WRONLY |O_CREAT|O_TRUNC,0644);
	if(fd < 0){
		perror("open failed");
		exit(1);
	}
	write(fd,"Hello world\n",12);
	close(fd);
	
	fd = open("honey.txt",O_RDONLY);
	bytes = read(fd,buffer,sizeof(buffer) - 1);
	buffer[bytes] = '\0';
	printf("Read :%s\n",buffer);
	close(fd);
	
	fd = open("honey.txt",O_RDWR);
	lseek(fd,0,SEEK_END);
	write(fd,"append\n",7);
	close(fd);
	
	struct stat st;
	stat("honey.txt",&st);
	printf("File size : %lld bytes\n",(long long)st.st_size);
	
	DIR *dir = opendir(".");
        struct dirent *entry;
        printf("Directory contents:\n");
        while ((entry = readdir(dir))) printf("%s\n", entry->d_name);
        closedir(dir);
	
	return 0;
}
	
	
	
