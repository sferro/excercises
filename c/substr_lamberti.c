#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ifnSubStr(char *pcDestino, int iPos, char *pcOrigen, int iOrigen, int iLargo)
{
    int t;		/* CONTADOR */
    
    /* VERIFICO LOS PARAMETROS */
    if(iPos <= 0 || iOrigen <= 0 || !pcDestino || !pcOrigen || !iLargo)
	return(1);
		    
    /* COPIO EL ORIGEN */
    for(t=0;t<iLargo;t++) *(pcDestino + (iPos - 1) + t) = *(pcOrigen + (iOrigen - 1) + t);
    
    return(0);
}

int ifnSubStr(char *pcDestino, int iPos, char *pcOrigen, int iOrigen, int iLargo);

int main(int argc, char **argv) {
    char szCadena[100];
    char szPoner[12];
    
    strcpy(szPoner, "abcdefghijk");
    strcpy(szCadena, "012345678989112zzzzzzzzzzzzzzzzzzzzzzz");
    
    ifnSubStr(szCadena, 4, szPoner, 1, 11);
    
    printf("Cadena=(%s)\n", szCadena);
    
    memset(szPoner, 0, 11);
    strncpy(szPoner, &szCadena[3], 5);
    
    printf("Poner= (%s)\n", szPoner);
    
    return 0;
}

