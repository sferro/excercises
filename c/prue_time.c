#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i;
    struct tm *ptr;
    time_t lt;
    char szCadena[100];
    
    lt = time(NULL);
    ptr = localtime(&lt);
    printf("Hora Inicio: %s", asctime(ptr));
    		        
    printf("ingreso la la fecha= 20020227010101\n");
    ptr->tm_year = 2002-1900;
    ptr->tm_mon = 2-1;
    ptr->tm_mday = 27;
    ptr->tm_hour = 1;
    ptr->tm_min = 1;
    ptr->tm_sec = 1;
    
    lt=mktime(ptr);
    
    strftime(szCadena, 100, "%Y%m%d%H%M%S", ptr);
    
    printf("szCadena= (%s)\n", szCadena);
    
    for(i = 0; i < 100; i++) {
	lt += 3600 + i;
	ptr = localtime(&lt);
	strftime(szCadena, 100, "%Y%m%d%H%M%S", ptr);
	printf("szCadena= (%s)\n", szCadena);
    }
    
    lt = time(NULL);
    ptr = localtime(&lt);
    printf("Hora fin: %s", asctime(ptr));
    
    return 0;
}

