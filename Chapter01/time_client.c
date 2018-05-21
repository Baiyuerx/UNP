#include "unp.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char *argv[])
{
	int sockfd, n;
	char line[MAXLINE + 1];
	struct sockaddr_in servaddr;
	struct sockaddr_in localaddr;
	socklen_t len;
	char buff[INET_ADDRSTRLEN];

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		err_sys("socket error");

	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("iner_pton error for %s", argv[1]);
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
		err_sys("connect error");
	len = sizeof(localaddr);
	if(getsockname(sockfd, (struct sockaddr*)&localaddr, &len) < 0)	
		err_sys("getsockname error");
	inet_ntop(AF_INET, &(localaddr.sin_addr), buff, INET_ADDRSTRLEN);
	printf("local adress:%s\n", buff);

	while ((n = read(sockfd, line, MAXLINE)) > 0)
	{
		line[n] = 0;
		if (fputs(line, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");
}
