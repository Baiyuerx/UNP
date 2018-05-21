#include "unp.h"

int main(int argc, char *argv[])
{
    int sockfd[5];
    struct sockaddr_in servaddr;

    if (argc != 2)
        err_quit("Usage: tcpcli <IPaddress>");
    for (int i = 0; i < 5; ++i)
    {
        sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(9877);
        Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
        Connect(sockfd[i], (SA *)&servaddr, sizeof(servaddr));
    }

    str_cli(stdin, sockfd[0]);
    exit(0);
}