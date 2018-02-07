#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double dConv_Monto(char *szCad);

int main(int argc, char **argv) {
    char szCadena[12], szCadtemp[100];
    double dNum;
    
    printf("ingresar numero en formato $$$$$$$$$cc: ");
    scanf("%s", szCadena);    
    
    printf("Cadena= (%s)\n", szCadena);
    
    printf("Segundos= %f\n", dConv_Monto(szCadena));    

    dNum=12.12342345;
    printf("Numero = 12.12342345\n");
    sprintf(szCadtemp, "%.2f", dNum);
    printf("Numero = %s\n", szCadtemp);
    dNum=atof(szCadtemp);
    printf("Numero = %f\n", dNum);
    return 0;
}

double dConv_Monto(char *szCad){
    char szTemp[13];
    int iLen;
    
    iLen = strlen(szCad);
    if(iLen > 1) {    
	memset(szTemp, 0, sizeof(szTemp));
        
	strncpy(szTemp, szCad, iLen-2);
        strcat(szTemp, ".");
        strcat(szTemp, &szCad[iLen-2]);
    }
    else {
	strcpy(szTemp, ".0");
	strcat(szTemp, szCad);
    }    
    return atof(szTemp);
}
