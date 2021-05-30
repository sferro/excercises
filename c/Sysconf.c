#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char **argv)
{
    long lVal;
    
    if(argc != 2) {
	printf("Usage: Sysconf <constant>\n");
	exit(1);
    }
    
    if( (lVal = sysconf(_SC_ARG_MAX)) < 0) 
	printf("La constante (%s) no es valida\n", argv[1]);
    else
	printf("Valor = %ld\n", lVal);

    exit(0);
}
