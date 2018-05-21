#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <limits.h>

int main()
{
	long open_max = sysconf(FOPEN_MAX);
	printf("%ld\n", open_max);
	exit(0);
}
