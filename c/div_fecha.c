/*
Recibe un archivo como parametro un archivo, fecha, error,
e imprime solo aquellas lineas PPLAN que la fecha sea mayor a 
la fecha pasada como paramtro y que tnegan el error, error; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(char *szCadena, int iPos, int iCant, char *szDestino);

int main(int argc, char **argv) {
	FILE *pfdArchivo;
	char szArchivo[FILENAME_MAX];
	char szBufArchivo[2048];
	char szFecha[20];
	char szFechaArch[20];
	int iLenFecha;
	char szPos[5];
	int iPos;
	
	if(argc < 4) {
		printf("Usar:\n");
		printf("\tdiv_fecha_err <file> <fecha> <pos_fecha>\n");
		printf("\tPos_fecha, tiene en cuenta pos = 0\n");
		exit(1);
	}
	
	strcpy(szArchivo, argv[1]);
	strcpy(szFecha, argv[2]);
	strcpy(szPos, argv[3]);
	
	iLenFecha = strlen(szFecha);
	iPos = atoi(szPos);
	 
	if( (pfdArchivo = fopen(szArchivo, "r")) == NULL ) {
		printf("ERROR: al abrir <%s>\n", szArchivo);
		exit(1);
	}
	
	while(!feof(pfdArchivo)) {
		if(fgets(szBufArchivo, 2047, pfdArchivo) == NULL)
			break;
 
		/*RESCATO LAS VARIABLES QUE NECESITO*/
		substr(szBufArchivo, iPos, iLenFecha, szFechaArch);
		
		if(strcmp(szFechaArch, szFecha ) > 0)
			fputs(szBufArchivo, stdout); 
		
	}
	
	exit(0);
		
}


/**********************************************************************************************
Nombre Funcion:			substr
Argumentos:				szCadena: Cadena fuente
						iPos: Posicion desde
						iCant: Cantidad de caracteres
						szDestino: Cadena destino
			
Valores que retorna:	szDestino, puntero a char
Descripcion:			Devuelve en szDestino una porcion de iCant caracteres de longitud, de 
						la cadena szCadena proporcionada como argumento, empezando a partir de
						la posicion iPos. La posicion iPos contempla la posicion 0.
						Se retorna una cadena de caracteres finalizada con nulo.
Observaciones:			El array apuntado por szDestino debe ser lo suficiente grande para 
						mantener el contenido de la cadena apuntada por szCadena. Si szCadena 
						y szDestino se solapan, el comportaniento queda indefinido.

**********************************************************************************************/
char *substr(char *szCadena, int iPos, int iCant, char *szDestino)
{
    
	strncpy(szDestino, &szCadena[iPos], iCant);
	szDestino[iCant]='\0';
    
	return szDestino;
}

