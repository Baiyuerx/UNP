#include "unp.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	int listenfd, connfd;
//	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, seraddr;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&seraddr, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(9877);
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd, (SA *)&seraddr, sizeof(seraddr));
	Listen(listenfd, LISTENQ);

	for (;;)
	{
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *)&cliaddr, &clilen);
//        if ((childpid = Fork()) == 0)
//       {
//           Close(listenfd);
		str_echo(connfd);
		Close(connfd);
//            exit(0);
//       }
		Close(connfd);
	}
}
