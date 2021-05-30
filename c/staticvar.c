#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char ROA_SID[10]="32145";

int main(int argc, char *argv[])
{
    printf("%s\n", ROA_SID);
    
    strcpy(ROA_SID, "99987");

    printf("%s\n", ROA_SID);
    
    return 0;
}

    