#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    struct tm *punt;
    time_t lt;
    char szCadena[15];
    
    lt= time(NULL);
    punt = localtime(&lt);
    printf(asctime(punt));
    
    lt=time(NULL);
    punt=localtime(&lt);
    strftime(szCadena, 15, "%Y%m%d%H%M%S", punt);
    
    printf("Hora= (%s)\n",szCadena);
    
    return 0;
}