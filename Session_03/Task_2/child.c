#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char * cmd = getenv("MY_COMMAND"); 
    if(cmd == NULL)
    {
        fprintf(stderr, "Child: MY_COMMAND not set\n");
        exit(1);
    }
    
    execlp(cmd, cmd, (char *)NULL);
    perror("execlp failed");
    exit(1);
}
