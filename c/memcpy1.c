#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCad[6];
    char szArgv[100];
    
    strcpy(szArgv, argv[1]);
    
    memset(szCad, 0, 6);
    
    memcpy(szCad, szArgv + 3, 5);
    
    printf("mem szCad %s\n", szCad);
    
    strncpy(szCad, szArgv + 3, 5);
    
    printf("mem szCad %s\n", szCad);
    
    return 0;
}
