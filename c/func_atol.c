#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char szTemp[10];
    long lTemp;
    
    strcpy(szTemp, "123   ");
    lTemp=atol(szTemp);
    
    printf("Numero= %d\n", lTemp);
    
    strcpy(szTemp, " 1234 ");
    lTemp=atol(szTemp);
    
    printf("Numero= %d\n", lTemp);
    
    strcpy(szTemp, "123.12 ");
    lTemp=atol(szTemp);
    
    printf("Numero= %d\n", lTemp);
    
    strcpy(szTemp, "12345");
    lTemp=atol(szTemp);
    
    printf("Numero= %d\n", lTemp);
    
    return 0;
}