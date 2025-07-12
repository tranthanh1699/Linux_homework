#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork(); 
    if(pid < 0)
    {
        perror("fork"); 
        return 1; 
    }

    if(pid == 0)
    {
        printf("Child: this is child process (PID %d), exit now\n", getpid()); 
        exit(0); 
    }
    else 
    {
        printf("This is parent process, sleep 30s\n"); 
        sleep(30); 
        printf("Parent sleep done\n"); 
    }
    return 0; 
}