#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *pfd;
    char szCadena[10];
    char szArchivo[100];
    int i, pos;
    
	
    if(argc < 2) {
	printf("Debe poner como parametro el nombre del archivo");
	exit (1);
    }
    
    strcpy(szArchivo, argv[1]);
    
    if((pfd = fopen(szArchivo,  "r")) == NULL) {
        printf("Error al abrir el archivo (%s)\n", szArchivo);
        exit(1);
    }
    
    /*leo la primera linea y luego vuelvo el archivo al principio*/
    
    while(fgets(szCadena, 10, pfd) !=NULL) {
        printf("szCadena = %s\n", szCadena);
    
    }
    if(feof(pfd))
        printf("Fin de archivo\n");
    else
        printf("Mal Lectura\n");
    

    
    return 0;
}
