#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ESTRUCT {
    int iNum;
    char szCad[10];
};


int InicStruct(struct ESTRUCT *s, int i, char *c) {
    s->iNum = i;
    strcpy(s->szCad, c);
    

    return 0;
}

int MostrarStruct(struct ESTRUCT *s) {
    printf("s->iNum= %d\n", s->iNum);
    printf("s->szCad = (%s)\n", s->szCad);

    return 0;
}

int main(int argc, char **argv) {
    struct ESTRUCT sSTRU;
    int i, n;
    char szC[10];
    
    for(i=0; i< 5; i++) {
    
	printf("\nNumero y Cadena\n"); 
	scanf("%d %s", &n, szC);
	
	InicStruct(&sSTRU, n, szC);
    
	MostrarStruct(&sSTRU);
    }    

    return 0;
}