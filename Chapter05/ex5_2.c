#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("binary", "wb");
    fwrite("10\n", sizeof(char), 4, fp);
    fclose(fp);
    return 0;
}