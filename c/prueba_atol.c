#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stderr.h>

int main(int argc, char **argv) {
    char szCadena[100];
    long lNumero;
    
    strcpy(szCadena, "0000123");
    lNumero=atol(szCadena);
    printf("0000123 se convirtio a = %d\n", lNumero);
    
    strcpy(szCadena, "a0000123");
    lNumero=atol(szCadena);
    if(errno)
	perror("Error ");
    printf("0000123 se convirtio a = %d\n", lNumero);
    
    strcpy(szCadena, " 0000123");
    lNumero=atol(szCadena);
    if(errno)
	perror("Error ");
    printf("0000123 se convirtio a = %d\n", lNumero);

    strcpy(szCadena, " 0000123");
    lNumero=strtol(szCadena, (char **)NULL, 10);
    printf("errno %d\n", errno);
    if(errno)
	perror("Error ");
    printf("0000123 se convirtio con strtol a = %d\n", lNumero);
    
    strcpy(szCadena, "a0000123");
    lNumero=atol(szCadena, (char **)NULL, 10);
    printf("errrno %d\n", errno);
    
    if(errno)
	perror("Error ");
    printf("0000123 se convirtio con strtol a = %d\n", lNumero);

    return 0;
}
    
    