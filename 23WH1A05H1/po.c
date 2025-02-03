#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buf[100];

    // Open the file for reading (this should not be used for writing)
    fd = open("do.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        return 1;
    }

    // Attempt to write to a file that is opened for reading (this is incorrect)
    // The write operation should be done on a file opened with O_WRONLY or O_RDWR
    // write(fd, "HELLO, WORLD!", 14); // This line is incorrect and should be removed

    // Close the file descriptor after reading
    close(fd);

    // Open the file for writing (create it if it doesn't exist)
    fd = open("do.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write to the file
    write(fd, "HELLO, WORLD!", 14);
    
    // Close the file after writing
    close(fd);

    // Open the current directory and read entries
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }

    struct dirent *ent;
    
    // Read directory entries and print them
    while ((ent = readdir(dir)) != NULL) {
        printf("%s\n", ent->d_name); // Corrected from /n to \n
    }

    // Close the directory stream
    closedir(dir);

    return 0;
}

