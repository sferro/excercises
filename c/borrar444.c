#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCadena[100];
    
    
    
    printf("sizeof(szCadena)= %d\n", sizeof(szCadena));
    
    memset(szCadena, '\0', sizeof(szCadena));
    printf("Cade = (%s)\n", szCadena);
    
    strcpy(szCadena, "*31#155077470");

    printf("Cade = (%s)\n", szCadena);
        
    strcpy(szCadena, "juan cruz legora");
    
    printf("Cade = (%s)\n", szCadena);
	
    strcpy(szCadena, "*31#155077470");	
	printf("Cade = (%s)\n", szCadena);
	
	strcpy(szCadena, &szCadena[4]);
	
	printf("Cade = (%s)\n", szCadena);
	

}
