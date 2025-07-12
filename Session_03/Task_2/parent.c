#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
    if(setenv("MY_COMMAND", "date", 1) != 0)
    {
        perror("setenv"); 
        return 1; 
    }

    char *argv[] = { "./child", NULL };
    if (execv("./child", argv) == -1) {
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
    return 0;
}