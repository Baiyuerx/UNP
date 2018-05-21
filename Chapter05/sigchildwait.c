#include "unp.h"
#include <sys/wait.h>

void sig_chld(int signo)
{
    pid_t pid;
    int state;

    pid = wait(&state);
    printf("child %d terminated\n", pid);
    return;
}