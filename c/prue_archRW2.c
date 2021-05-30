#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ifnEscribirArchivo(FILE *pfd, int num)
{
    printf("ftell = %d\n", ftell(pfd));
    fprintf(pfd, "%02d Linea %02d\n", num, num);

    return 0; 
}

int ifnImprimirUltimaLinea(FILE *pfd )
{
    char szCadena[200];
    long iCurPos;
    
    iCurPos = ftell(pfd);
    
    fseek(pfd, iCurPos - 12, SEEK_SET);
    fgets(szCadena, 199, pfd);	    
    
    printf("szCad= %s", szCadena);
        
    fseek(pfd, iCurPos, SEEK_SET);
        
    return 0;
}

int main(int argc, char **argv)
{
    FILE *pfdArchivo;
    int i=0;
    
    if((pfdArchivo=fopen("archivoRW.txt", "w+"))==NULL) {
	printf("No se puedo abrir el archivo\n");
	exit(1);
    }
    
    ifnEscribirArchivo(pfdArchivo, i); i++;
    ifnEscribirArchivo(pfdArchivo, i); i++;
    ifnEscribirArchivo(pfdArchivo, i); i++;
    ifnEscribirArchivo(pfdArchivo, i); i++;
    
    for(i= 4; i<50; i++) {
        ifnEscribirArchivo(pfdArchivo, i);
	ifnImprimirUltimaLinea(pfdArchivo);
    }
    
    fclose(pfdArchivo);   

}
