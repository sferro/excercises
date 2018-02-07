#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int iRes;
    struct stat *st;
    char szArchivo[FILENAME_MAX];
        
    strcpy(szArchivo, argv[1]);
    
    if((iRes= access(szArchivo, F_OK))==0 ) {
	printf("El archivo (%s) existe\n", szArchivo);
	if((iRes = stat(szArchivo, st))== 0) {
	    printf("Tamano de archivo (%s) = %d\n", szArchivo, st->st_size);
	        
	}
    }
    else {
	printf("El archivo (%s) No existe\n", szArchivo);
	printf("iRes= %d\n", iRes);
    }

    strcpy(szArchivo, argv[2]);
    
    if((iRes= access(szArchivo, F_OK))==0 ) {
	printf("El archivo (%s) existe\n", szArchivo);
	if((iRes = stat(szArchivo, st))== 0) {
	    printf("Tamano de archivo (%s) = %d\n", szArchivo, st->st_size);
	        
	}
    }
    else {
	printf("El archivo (%s) No existe\n", szArchivo);
	printf("iRes= %d\n", iRes);
    }
    return 0;

}
