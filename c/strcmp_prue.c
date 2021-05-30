#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char szCad1[100];
    char szCad2[100];
    
    if(argc < 3) {
	printf("Usar:\n");
	printf("\tstrcmp_prue <cadena1> <cadena2>\n");
	exit(1);
    }
    
    strcpy(szCad1, argv[1]);
    strcpy(szCad2, argv[2]);
    
    printf("Res= %d\n", strcmp(szCad1, szCad2));
    
    return 0;
}