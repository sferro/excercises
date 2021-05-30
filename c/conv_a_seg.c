#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iConv_seg(char *szCad);

int main(int argc, char **argv) {
    char szCadena[10];
    
    printf("ingresar numero en formato mmmmss: ");
    scanf("%s", szCadena);    
    
    printf("Cadena= (%s)\n", szCadena);
    
    printf("Segundos= %d\n", iConv_seg(szCadena));    

    return 0;
}

int iConv_seg(char *szCad){
    int iSegundos, iSeg, iMin;
    char szSeg[3], szMin[5];
    int iLen;
    
    iLen = strlen(szCad);
    
    if(iLen > 1) {
    
	memset(szMin, 0,  sizeof(szMin));
    
        strncpy(szMin, szCad, iLen-2);
	strcpy(szSeg, &szCad[iLen-2]);
    
	iMin = atoi(szMin);
        iSeg = atoi(szSeg);
    
        iSegundos = (iMin * 60) + iSeg;  
    }
    else {
	iSegundos = atoi(szCad);
    }
    return iSegundos;
}
