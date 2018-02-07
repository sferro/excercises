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

    strcpy(szSHELL, argv[1]);
    
    
    if( (pfdPopen = popen(szSHELL, "r")) == NULL) {
	  printf("No se pudo ejecutar popen\n");
	  exit(2);
    }

    while(fgets(szLinea, 255, pfdPopen) != NULL) {
	    printf("szLinea= %s", szLinea);
	}
	    
    if(pclose(pfdPopen) == -1) {
	  printf("Error al cerrar popen\n");
	  exit(3);
    }
    
    return 0;
    
}
