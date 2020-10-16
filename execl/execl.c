#include "stdio.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
    printf("begining...\n");
    if (fork() == 0)
    {
        execl("/bin/ls", "ls", "-l", NULL);
    }

    printf("--------------------\n");

    char *args[] = {"ls", "-l", NULL};
    if (fork() == 0)
    {
        if (execv("/bin/ls", args) == -1)
        {
            perror("exev error");
        }
    }

    printf("ending...\n");

    return 0;
}
