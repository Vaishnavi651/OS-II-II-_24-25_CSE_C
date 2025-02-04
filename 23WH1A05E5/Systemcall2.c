#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main()
{
char buffer[100];
ssize_t bytes;
int fd = open("example.txt",O_WRONLY|O_CREAT);
if(fd < 0)
{
printf("open failed");
return 1;
}
write(fd,"hello world\n",12);
close(fd);
fd = open("example.txt",O_RDONLY);
bytes = read(fd,buffer,sizeof(buffer)-1);
buffer[bytes] = '\0';
printf("The contents of the file : %s\n",buffer);
close(fd);
fd = open("example.txt",O_WRONLY);
lseek(fd,0,SEEK_END);
write(fd,"This is my first program\n",25);
close(fd);
struct stat st;
stat("example.txt",&st);
printf("File size : %lld bytes\n",(long long)st.st_size);
DIR *dir = opendir(".");
struct dirent *entry;
printf("Directory contents : \n");
while((entry = readdir(dir))) printf("%s\n",entry->d_name);
closedir(dir);
return 0;
}

