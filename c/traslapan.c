#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char str1[10];
    char str2[15];
    
    if(argc < 2) {
	printf("Debe ingresar al menos un paramentro\n");
	exit(1);
    }
    
    printf("str2[15]= %s\n", argv[1]);
    strcpy(str2, argv[1]);
    
    
    printf("str1[10] = str2[15]\n");
    strcpy(str1, str2);
    printf("str1 = %s\n", str1);
    
    /*Inicializo con asignacion*/
    printf("str1=\"\"\n");
    str1[0]='\0';
    printf("str1= %s\n", str1);
    
    /*Inicializo con memset*/
    printf("str2=\"\"\n");
    memset(str2,'\0', 15);
    printf("str2= %s\n", str2);
    
    
    
    printf("Fin de proceso\n");
    return 0;
}
