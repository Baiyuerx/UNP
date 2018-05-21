#include "unp.h"

void str_echo(int sockfd)
{
	char line[MAXLINE];
	FILE *fpin, *fpout;

	fpin = fdopen(sockfd, "r");
	fpout = fdopen(sockfd, "w");

	while (Fgets(line, MAXLINE, fpin) != NULL)
	{
		Fputs(line, fpout);
		fflush(fpout);
	}
}
