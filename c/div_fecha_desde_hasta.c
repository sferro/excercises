/*
Recibe un archivo como parametro un archivo, fecha_desde y fecha_hasta
e imprime solo aquellas lineas PPLAN que la fecha sea mayor y menor a 
las fechas pasadas como paramteros; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *substr(char *szCadena, int iPos, int iCant, char *szDestino);

int main(int argc, char **argv) {
	FILE *pfdArchivo;
	char szArchivo[FILENAME_MAX];
	char szBufArchivo[200];
	char szFecha_desde[15];
	char szFecha_hasta[15];
	char szFechaArch_desde[15];
	char szFechaArch_hasta[15];
	char szTIP_REG[3];
	int iLenFecha_desde;
	int iLenFecha_hasta;
	
	if(argc < 4) {
		printf("Usar:\n");
		printf("\tdiv_fecha_err <file> <fecha_desde> <fecha_hasta>\n");
		exit(1);
	}
	
	strcpy(szArchivo, argv[1]);
	strcpy(szFecha_desde, argv[2]);
	strcpy(szFecha_hasta, argv[3]);
	
	iLenFecha_desde = strlen(szFecha_desde);
	iLenFecha_hasta = strlen(szFecha_hasta);
	 
	if( (pfdArchivo = fopen(szArchivo, "r")) == NULL ) {
		printf("ERROR: al abrir <%s>\n", szArchivo);
		exit(1);
	}
	
	while(!feof(pfdArchivo)) {
		if(fgets(szBufArchivo, 199, pfdArchivo) == NULL)
			break;
 
		/*RESCATO LAS VARIABLES QUE NECESITO*/
		substr(szBufArchivo, 14, iLenFecha_desde, szFechaArch_desde);
		substr(szBufArchivo, 14, iLenFecha_hasta, szFechaArch_hasta);
		substr(szBufArchivo, 0, 2, szTIP_REG);
		
		if( strcmp(szFechaArch_desde, szFecha_desde ) > 0 && 
			  strcmp(szFechaArch_hasta, szFecha_hasta ) < 0 && 
			  !strcmp(szTIP_REG, "02"))
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

