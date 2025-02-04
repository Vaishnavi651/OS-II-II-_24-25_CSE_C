#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>

int main(){
        int fd;
        char buffer[100];
        struct dirent *entry;
        struct stat filestat;
        DIR *dir;

        // Open file for reading and writing
        fd = open("newfile.txt", O_RDWR | O_CREAT, 0644);
        if(fd < 0){
                perror("Error occurred in opening the file");
                return 1;
        }

        // Write to the file
        if (write(fd, "I am still learning.", 25) == -1) {
                perror("Error writing to file");
                close(fd);
                return 1;
        }

        // Move the file pointer to the 5th byte from the current position
        if (lseek(fd, 5, SEEK_CUR) == -1) {
                perror("Error with lseek");
                close(fd);
                return 1;
        }

        // Read the content of the file into the buffer
        if (read(fd, buffer, 25) == -1) {
                perror("Error reading from file");
                close(fd);
                return 1;
        }

        buffer[20] = '\0';  // Null-terminate the buffer

        // Close the file
        close(fd);

        // Check file size of "Systemcalls.txt"
        if(stat("Systemcalls.txt", &filestat) == 0){
                printf("File size: %ld bytes\n", filestat.st_size);
        } else {
                perror("ERROR: Systemcalls.txt does not exist or cannot be accessed");
        }

        // Open current directory for reading
        dir = opendir(".");
        if (dir == NULL) {
                perror("Could not open current directory");
                return 1;
        }

        printf("The directory contents are: \n");

        // Read and display the directory contents
        while ((entry = readdir(dir)) != NULL) {
                printf("inode number: %ld\nname: %s\n", (long) entry->d_ino, entry->d_name);
        }

        // Close the directory stream
        closedir(dir);

        return 0;
}

