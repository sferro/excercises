#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char szTemp[10];
    char szCadena[1000];
    
    memset(szTemp, 0, 10);
    strcpy(szCadena, "abcdef0814");
    
    strcpy(szTemp, "2002");
    strncpy(&szTemp[4], &szCadena[6], 4);
    
    printf("szTemp= (%s)\n", szTemp);
    
    return 0;
    
}
