#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ifnEscribirArchivo(FILE *pfd, int num)
{
    fprintf(pfd, "%d Linea %*d\n", num, num, num);
    return 0; 
}

int ifnImprimirUltimaLinea(FILE *pfd )
{
    char szCadena[200];
    static long i=0;
    long iCurPos;
    
    iCurPos = ftell(pfd);
    
    fseek(pfd, 0, SEEK_SET);
    while(fgets(szCadena, 199, pfd)!=NULL);
/*	printf("Cadenawhile = (%s)\n",szCadena);
    }
/*    fgets(szCadena, 199, pfd);	    */
        
    if(szCadena[0] == '0') {
	printf("primera cadena\n");
	fgets(szCadena, 199, pfd);
	printf("szCadena= %s", szCadena);
    }
    else {    
	printf("szCadena_1= %s", szCadena);
    }
    fseek(pfd, iCurPos, SEEK_SET);
    
    i = iCurPos;
    
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
    
    ifnEscribirArchivo(pfdArchivo, i);
    
    for(i= 1; i<50; i++) {
        ifnEscribirArchivo(pfdArchivo, i);
	ifnImprimirUltimaLinea(pfdArchivo);
    }
    
    fclose(pfdArchivo);   

}
