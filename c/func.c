#include <stdio.h>
#include <math.h>
#include <string.h>

void imprimir();
char cad[50]="Esto es una prueba";
int main(int argc, char *argv[]) {
	int letra;
	
	letra = 'S';
	
	if ('S' == 83) {
		
		printf("La letra es %c\n", letra);
		printf("La letra es %d\n", letra);
	}
	
	imprimir();
	
	return 0;
}

void imprimir() {
	printf("La cadena es: %s\n", cad);
}
	
	
