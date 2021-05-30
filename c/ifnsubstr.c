#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ifnSubStr(char *pcDestino, int iPos, char *pcOrigen, int iOrigen, int iLargo);


int main(int argc, char *argv[]) {
    char szOrigen[100];
    char szDestino[100];
    
    strcpy(szOrigen, argv[1]);
    
    ifnSubStr(szDestino, 1, szOrigen, 5, 5);
    
    printf("Origen= %s\n", szOrigen);
    printf("Destino= %s\n", szDestino);
    
    return 0;

}

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
				