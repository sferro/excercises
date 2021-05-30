#include <stdio.h>
#include <string.h>

#define MAX 100

struct n {
    long codigo;
    char fname[50];
    char lname[50];
};

typedef struct n nombres;

int main(int argc, char **argv) {
    nombres nombre[MAX];
    char strTemp[50];
    long i, num, iter, dif, mitad, mitad_i, mitad_f;

    str
    for(i=0; i<MAX; i++) {
	nombre[i].codigo=i;
	sprintf(nombre[i].fname, "Sebastian_%ld", i);
	sprintf(nombre[i].lname, "Ferro_%ld", i);
    }

    for(i=0; i<MAX; i++) {
	printf("%ld ; %s ; %s\n", nombre[i].codigo, nombre[i].fname, nombre[i].lname);
    }

    printf("Ingrese un valor a buscar: ");
    scanf("%d", &num);
    
    iter = 0;
    mitad_f = MAX;
    mitad_i = 0;

    mitad = (mitad_f - mitad_i)/ 2 + 1;
    while(1) {
	if(nombre[mitad].codigo == num) {
	    printf("%ld ; %s ; %s\n", nombre[mitad].codigo, nombre[mitad].fname, nombre[mitad].lname);
	    break;

	}
	if(num > nombre[mitad].codigo) {
	    mitad_i = mitad;
	    mitad = (mitad_f + mitad_i) / 2;
	    printf("_mitad = %d\n", mitad);
	    printf("%ld ; %s ; %s\n", nombre[mitad].codigo, nombre[mitad].fname, nombre[mitad].lname);
	}
	else {
	    mitad_f = mitad;
	    mitad = (mitad_f + mitad_i) / 2;
	    printf("mitad = %d\n", mitad);
	    printf("%ld ; %s ; %s\n", nombre[mitad].codigo, nombre[mitad].fname, nombre[mitad].lname);
	}
	iter++;
	if( iter > 100)
	    break;
    }
    if (iter > 100)
	printf("No se encontro\n");
    else {
	printf("Encontrado en %10d iteraciones\n", iter);
	printf("%ld ; %s ; %s\n", nombre[mitad].codigo, nombre[mitad].fname, nombre[mitad].lname);
    }
	    
     
    printf("FIN\n");
    return 0;
}
