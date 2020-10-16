#include "unistd.h"
#include "stdio.h"

int main(int argc, char const *argv[]) {
    printf("uid: %d, gid: %d\n", getuid(), getgid());
    printf("euid: %d, egid: %d\n", geteuid(), getegid());

    int i;
    for ( i = 0; i < argc; i++){
       printf("arg %d is %s\n", i, argv[i]);
    }


    return 0;
}
