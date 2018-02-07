#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    
    exit(0);
}
