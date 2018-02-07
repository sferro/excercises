#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCadena1[10];
    char szCadena2[6];
    
    strcpy(szCadena1, "123456789");
	
    memcpy(szCadena2, szCadena1, 5);
    printf("szCadena2= %s\n", szCadena2);
    if(szCadena2[5]==0)
	printf("la Cadena2 termina en nulo\n");


    strncpy(szCadena2, szCadena1, 5);
    
    printf("szCadena2= %s\n", szCadena2);
    if(szCadena2[5]==0)
	printf("la Cadena2 termina en nulo\n");
    
    szCadena1[0]='\0';
    szCadena2[0]='\0';
        
    printf("Cadena1 = %s\n", szCadena1);
    printf("Cadena2 = %s\n", szCadena2);
    
    printf("resultado comp = %d\n", strcmp(szCadena1, szCadena2));
    
    if(szCadena1 == NULL)
	printf("Cadena1 = NULL\n");

    if(szCadena1[0] == 0)
	printf("Cadena1 = NULO\n");

    strcpy(szCadena1, "1234");
    
    printf("resultado comp = %d\n", strcmp(szCadena1, szCadena2));
            
    printf("Cadena1 = %s\n", szCadena1);
    
    szCadena1[0]=0;
    printf("Cadena1 = %s\n", szCadena1);
    
    return 0;
    
}
