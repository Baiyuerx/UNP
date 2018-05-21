#include "unp.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, seraddr;
    void sig_chld(int);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);

    bzero(&seraddr, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(9877);
    seraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    Bind(listenfd, (SA *)&seraddr, sizeof(seraddr));
    Listen(listenfd, LISTENQ);
    signal(SIGCHLD, sig_chld);

    for (;;)
    {
        clilen = sizeof(cliaddr);
        if ((connfd = accept(listenfd, (SA *)&cliaddr, &clilen)) < 0)
        {
            if (errno == EINTR)
                continue;
            else
                err_sys("accept error");
        }
        if ((childpid = Fork()) == 0)
        {
            Close(listenfd);
            str_echo(connfd);
            Close(connfd);
            exit(0);
        }
        Close(connfd);
    }
}
