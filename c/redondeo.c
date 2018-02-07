#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float redondeo(float num);

int main(int argc, char *argv[]) {
    float dNumero;

    do {
	printf("Ingrese un numero:\n");
	scanf("%f", &dNumero);
	
	printf("numero redondeado = %f\n", redondeo(dNumero));
    } while(dNumero != -1.0);	
    return 0;
}

float redondeo(float num) {
    char szNum[10];
    
    memset(szNum, 0, 10);
    
    sprintf(szNum, "%.2f", num);
    
    return atof(szNum); 
}
	
	
