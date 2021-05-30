#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char szLinea[256];
    char szSHELL[256];
    FILE *pfdPopen;
    int num;
    
    if(argc != 2) {
	printf("Error en los parametros, debe indicar la ruta\n");
	exit (1);
    }

    strcpy(szSHELL, "ls ");
    strcat(szSHELL, argv[1]);
    strcat(szSHELL, "*.c");
    
    
    if( (pfdPopen = popen(szSHELL, "r")) == NULL) {
	printf("No se pudo ejecutar popen\n");
	exit(2);
    }

    scanf("%d", &num);
    while(fgets(szLinea, 255, pfdPopen) != NULL) {
	if(!strncmp(szLinea, argv[1], strlen(argv[1])))
	    printf("szLinea= %s", &szLinea[strlen(argv[1])]);
	else {
	    printf("szLinea= %s", szLinea);
	    scanf("%d", &num);
	}
	
    }
    
    
    if(pclose(pfdPopen) == -1) {
	printf("Error al cerrar popen\n");
	exit(3);
    }
    
    return 0;
    
}
