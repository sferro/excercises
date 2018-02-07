#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *pcGen1;


    pcGen1 = malloc(sizeof(char)*25);
    
    pcGen1 = getenv("WORK");
    
    if(!pcGen1) printf("No se pudo obtener la variable de entorno $WORK");
    
    if(strlen(pcGen1) == 0) 
	printf("La variable de entorno $WORK no esta inicializada");
    if(pcGen1[strlen(pcGen1)-1] != '/') strcat(pcGen1,"/");
    
    printf("WORK= (%s)\n", pcGen1);

}
