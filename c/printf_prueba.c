#include <stdio.h>

int main(int argc, char **argv) {
    int n=123;
    char szCad[100];
    
    strcpy(szCad, "Esto es una prueba de szCad");
    
    printf("El numero es= %.5d\n", n);
    
    sprintf(szCad, "%d", n);
    
    printf("La cadena es= %05s\n", szCad);
	
	printf("La cadena es= %14.14s\n", szCad);
    
	printf("La cadena es= %14s\n", szCad);

	printf("La cadena es= %1.14s\n", szCad);

    return 0;
}
