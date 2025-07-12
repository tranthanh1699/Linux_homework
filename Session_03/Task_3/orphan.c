#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork(); 

    if(pid == 0)
    {
        // Child process
        printf("Child: Child process (PID %d), my parent proces (PID %d)\n", getpid(), getppid()); 
        sleep(10); 
        printf("Child: Child process (PID %d), my new parent proces (PID %d)\n", getpid(), getppid()); 
    }
    else 
    {
        printf("Parent process (PID %d) is exitting...\n", getpid()); 
        exit(0); 
    }
    return 0; 
}