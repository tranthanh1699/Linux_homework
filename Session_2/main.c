#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])   
{
    if (argc < 2) {
        printf("No arguments provided.\n");
        printf("Usage: ./filestat <file_path>\n");
        return 1;
    }

    struct stat sb; 

    if(lstat(argv[1], &sb) == -1) {
        perror("lstat");
        return 1;
    }
    
    // print file path user input
    printf("File path: %s\n", argv[1]);
    
    // print file type
    if (S_ISREG(sb.st_mode)) {
        printf("File type: Regular file\n");
    } else if (S_ISDIR(sb.st_mode)) {
        printf("File type: Directory\n");
    } else if (S_ISLNK(sb.st_mode)) {
        printf("File type: Symbolic link\n");
    } else if (S_ISCHR(sb.st_mode)) {
        printf("File type: Character device\n");
    } else if (S_ISBLK(sb.st_mode)) {
        printf("File type: Block device\n");
    } else if (S_ISFIFO(sb.st_mode)) {
        printf("File type: FIFO (named pipe)\n");
    } else if (S_ISSOCK(sb.st_mode)) {
        printf("File type: Socket\n");
    } else {
        printf("File type: Unknown\n");
    }

    // print file size
    printf("File size: %lld bytes\n", (long long)sb.st_size);
    // print last access time
    time_t last_access = sb.st_atime;
    struct tm *tm_info = localtime(&last_access);
    char buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last access time: %s\n", buffer);
    // print last modification time
    time_t last_modification = sb.st_mtime;
    tm_info = localtime(&last_modification);
    buffer[26];
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last modification time: %s\n", buffer);
    // print last status change time
    time_t last_status_change = sb.st_ctime;
    tm_info = localtime(&last_status_change);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last status change time: %s\n", buffer);
    
    return 0;
}