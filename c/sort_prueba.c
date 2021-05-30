#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(array) (sizeof(array) / sizeof(array[0]))

#define MAX_ELEM 20

int CargarArrayDes(char *szArCad[], int iLen);
void ImprimirArray(char *szArCad[], int iLen);
int node_compare( const void *node1, const void *node2);
int OrdenarArray(char *szArCad[], int iLen);


int OrdenarArray(char *szArCad[], int iLen)
{
    qsort(szArCad, MAX_ELEM, sizeof(szArCad[0]), node_compare);    
}

int node_compare( const void *node1, const void *node2) 
{
    char *v1, *v2;
    v1 = *(char **) node1;
    v2 = *(char **) node2;
    
    return ( strcmp(v1, v2));
}

void ImprimirArray(char *szArCad[], int iLen) 
{
    int i;
        
    for(i=0; i < iLen; i++) {
	printf("%s\n", szArCad[i]);
    }
    
}

int CargarArrayDes(char *szArCad[], int iLen)
{
    int i;
    char szCadena[100];
    
    for(i=0; i<iLen; i++) {
	sprintf(szCadena, "%d", rand()); 
	szArCad[i] = (char *)malloc(sizeof(char) * (strlen(szCadena) + 1));
	strcpy(szArCad[i], szCadena);
	
    }
    
    return 0;
}
	        

int main(int argc, char *argv)
{
    char **szArray;
    
    szArray = (char **)malloc(sizeof(char *) * MAX_ELEM);
    
    CargarArrayDes(szArray, MAX_ELEM);
    
    printf("Array Desordendo\n");
    ImprimirArray(szArray, MAX_ELEM);
    
    printf("Ordenando Array\n");
    OrdenarArray(szArray, MAX_ELEM);
    
    printf("Array Ordenado\n");
    ImprimirArray(szArray, MAX_ELEM);

    exit(0);
}
