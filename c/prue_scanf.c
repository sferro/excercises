#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char szA[10];
    char szCadena[5];
    char szB[10];
    
    strcpy(szA, "AAAAA");
    strcpy(szB, "BBBBB");
    
/*    scanf("%[^\n]s", szCadena);*/
    scanf("%s", szCadena);
    printf("%s\n", szCadena);    
    printf("%s\n", szA);   
    printf("%s\n", szB);    

    fgets(szCadena, 100, stdin);
/*  printf("Introduzca cadena\n");
    gets(szCadena);
    printf("%s\n", szCadena);    
*/        
    printf("Introduzca cadena\n");
    fgets(szCadena, 100, stdin);
    printf("%s\n", szCadena);    
    printf("%s\n", szA);   
    printf("%s\n", szB);    

    return 0;
}
