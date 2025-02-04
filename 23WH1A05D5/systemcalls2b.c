#include <stdio.h>      // Standard I/O functions (printf, perror)
#include <stdlib.h>     // Standard library functions (exit, etc.)
#include <unistd.h>     // POSIX API (read, write, close, lseek)
#include <fcntl.h>      // File control options (open flags)
#include <sys/stat.h>   // File status structure (stat)
#include <dirent.h>     // Directory operations (opendir, readdir)

int main() {
  
    int file = open("example.txt", O_WRONLY | O_CREAT, 0644);
    if (file == -1) {
        // If open() returns -1, an error occurred.
        perror("Open failed");
        return 1;
    }

    // Write to the file.
    const char *text = "Hello, this is a test file.\n";
    write(file, text, 26);
    // Close the file.
    close(file);

    file = open("example.txt", O_RDONLY);
    if (file == -1) {
        perror("Open failed");
        return 1;
    }

    char buffer[27];
    read(file, buffer, 26);
    buffer[26] = '\0';
    printf("Content of example.txt: %s\n", buffer);
    lseek(file, 0, SEEK_SET);
  
    read(file, buffer, 26);
    buffer[26] = '\0';
    printf("Content of example.txt after lseek: %s\n", buffer);

   
    close(file);

    struct stat fileStat;
    stat("example.txt", &fileStat);
    printf("File size: %ld bytes\n", fileStat.st_size);
    DIR *dir = opendir(".");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    
    closedir(dir);

    return 0;
}
