#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<dirent.h>
#include<string.h>

int main()
{
int fd;
char buffer[20];
ssize_t b_read,b_written;
const char *data="System calls ";
fd=open("file.txt",O_RDWR|O_CREAT);
if(fd==-1)
{
	printf("Failed to open file\n");
	return 1;
}	
b_written=write(fd,data,strlen(data));
if(b_written==-1){
	printf("Failed to write in the file\n");
	close(fd);
	return 1;
}
b_read=read(fd,buffer,sizeof(buffer)-1);
if(b_read==-1)
{
	printf("Failed to read the content in the file");
	close(fd);
	return 1;
}	
buffer[b_read] = '\0'; // Null-terminate the buffer
    printf("Read from file: %s\n", buffer);
 // Directory operations
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Failed to open directory");
        return 1;
    }

    struct dirent *entry;
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    if (closedir(dir) == -1) {
        perror("Failed to close directory");
        return 1;
    }

    return 0;


}	
