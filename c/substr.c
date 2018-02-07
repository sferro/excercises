#include <stdio.h>
#include <string.h>

char *GENSubStr(char *sStrSource,int iStartPos, int iQttyChar, char *sStrTarget);
int GENGetPosChar(char *sStr, int iChar, int iInitPos);

int main(int argc, char **argv) {
    char szCadena[50];
    char szTemp[50];
    char szSource[200], szTarjet[200];
    int ipos;
    
    strcpy(szCadena, "+5435101234567890");
    ipos = GENGetPosChar(szCadena, '2', 0);
    

    printf("ipos= %d\n", ipos);
    
    szCadena[ipos]='B';
    strcpy(szCadena, &szCadena[3]);
    
    printf("Cadena= %s\n", szCadena);
    
    memset(szTemp, '\0', 50);
    GENSubStr(szCadena, 3, 3, szTemp);
    
    printf("szTemp= %s\n", szTemp);
    printf("szCadena= %s\n", szCadena);
    
    printf("resultado de comparacion= %d\n", strncmp(GENSubStr(szCadena, 0, 3, szTemp), "01", 2));
    
    printf("resultado de comparacion= %d\n", strncmp("012344", "01", 2));

    printf("szCadena[4]= %s\n", &szCadena[5]);
    
    szCadena[4]='\0';
    
    printf("szCadena = %s\n", szCadena); 
    
    strcpy(szSource, "0540132129500011XXXXXXXX+542202XXXXXXXXXXXDDN01");
    memset(szTarjet, 0, 17);
    GENSubStr(szSource, 0, 16, szTarjet);
    printf("cgi= %s\n",szTarjet);
    memset(szTarjet, 0, 8);
    GENSubStr(szSource, 24, 7, szTarjet);
    printf("Destino= %s\n",szTarjet);
    memset(szTarjet, 0, 6);
    GENSubStr(szSource, 42, 5, szTarjet);
    printf("desc= %s\n",szTarjet);
     
    
    
    
    return 0;
}

char *GENSubStr(char *sStrSource,int iStartPos, int iQttyChar, char *sStrTarget)
{
    int x;
    x = 0;
    while(x < iQttyChar){
	sStrTarget[x++] = sStrSource[iStartPos++];
    }
    return(sStrTarget);
}


/**************************************************************************
* Busca una caracter dentro de una cadena
* Retorna: >= 0 posicion del caracter dentro de una cadena. Caracter Encontrado
*          < 0 caracter no encontrado
* Parametros:   sStr = cadena fuente
*               iChar = caracter a buscar
**************************************************************************/
int GENGetPosChar(char *sStr, int iChar, int iInitPos)
{
    int x;
    int iLenStr;
    int iPos;
			
    iPos = -1;
    iLenStr = strlen(sStr);
    for(x=iInitPos; x < iLenStr; x++){
	if(sStr[x] == iChar){
	    iPos = x;
	    break;
	}
    }
    return(iPos);
}
