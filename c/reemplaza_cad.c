#include <stdio.h>

int main(int argc, char **argv) 
{
    char szArchivo[FILENAME_MAX], szCadena[200];
    FILE *fpArchivo_i, *fpArchivo_o;
    
    
    if(argc<2) {
	printf("Debe ingresar el nombre del archivo como parametro\n");
	exit(1);
    }
    
    strcpy(szArchivo, argv[1]);
    
    if((fpArchivo_i=fopen(szArchivo, "r"))==NULL) {
	printf("No se puede abrir el archivo\n");
	exit(1);
    }
    
    if((fpArchivo_o=fopen("salida.txt", "w"))==NULL) {
	printf("No se puede abrir el archivo salida\n");
	exit(1);
    }
    
    while(!feof(fpArchivo_i)) {
	fgets(szCadena, 200, fpArchivo_i);
	if(szCadena[12]!=' ') {
	    szCadena[10]='X';
	    szCadena[11]='X';
	}
	else
	    continue;
	fprintf(fpArchivo_o, "%s", szCadena);
    }
    
    fclose(fpArchivo_o);
    fclose(fpArchivo_i);
    
    return 0;
}