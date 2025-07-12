#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void)
{
    pid_t pid = fork(); 
    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    if(pid == 0)
    {
        printf("Child (PID %d) will exit with code 10\n", getpid());
        exit(10); 
    }
    else 
    {
        // Parent process
        printf("Parent: My PID is %d, My child's PID is %d\n", getpid(), pid); 
        int status; 
        pid_t w = waitpid(pid, &status, 0); 
        if(w < -1)
        {
            perror("waitpid"); 
            return 1; 
        }

        if(WIFEXITED(status))
        {
            int code = WEXITSTATUS(status);
            printf("Parent: child %d exited normally with code %d\n", w, code);
        }
        else if (WIFSIGNALED(status)) {
            int sig  = WTERMSIG(status);
            printf("Parent: child %d was terminated by signal %d\n", w, sig);
        }
        else {
            printf("Parent: child %d ended abnormally (other reason)\n", w);
        }
    }

    return 0;
}