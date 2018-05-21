#include "unp.h"
#include <sys/wait.h>

void sig_chld(int signo)
{
    pid_t pid;
    int state;

    while ((pid = waitpid(-1,&state, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);
    return;
}
