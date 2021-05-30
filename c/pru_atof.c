#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char szNumero1[100];
    char szNumero2[100];
    
    double dNumero1, dNumero2;
    
    if(argc != 3) {
	printf("No se ingresaron los 2 paramentros\n");
	exit(1);
	
    }

    strcpy(szNumero1, argv[1]);
    strcpy(szNumero2, argv[2]);
    
    dNumero1 = atof(szNumero1);
    dNumero2 = atof(szNumero2);
    
    printf("Numero 1= %lf\n", dNumero1);

    printf("Numero 2= %lf\n", dNumero2);

    return 0;    
}
