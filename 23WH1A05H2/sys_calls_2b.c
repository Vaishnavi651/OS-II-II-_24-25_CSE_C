#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>

int main() {
    int fd;
    char buff[100];
    fd = open("sample.txt",O_WRONLY | O_CREAT, 0644);
    if(fd==-1){
        perror("Error has occured!");
        return 1;
    }
    write(fd,"Hello\n",7);
    close(fd);
    fd = open("sample.txt", O_RDONLY);
    if(fd==-1){
        perror("Error ochindi ra samba");
    }
    read(fd,buff,sizeof(buff));
    printf("Read from file: %s",buff);
    close(fd);
    off_t offset = lseek(fd,0, SEEK_SET);
    if(offset == (off_t)-1){
        perror("Error ra orey");
        return 1;
    }
    struct stat fs;
    if(lstat("sample.txt",&fs) == -1){
        perror("Error");
    }
    printf("File size: %lld bytes\n",(long long)fs.st_size);
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if(dir==NULL){
        perror("Error in opening");
        return 1; 
    }
    printf("Directory contents: \n");
    while((entry =  readdir(dir)) != NULL){
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
    return 0;
}   
