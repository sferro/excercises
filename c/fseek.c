#include <stdio.h>
#include <string.h>

long filesize(FILE *stream);
long RecordCount(FILE *stream);

int main(int argc, char **argv)
{
    FILE *stream;
    char szCad[100], szArchivo[FILENAME_MAX];
    
    if(argc != 2) {
	printf("Error en los parametros\n");
	printf("Debe ingresar: <Nombre de archivo>\n");
	exit(1);
    }   
    
    strcpy(szArchivo, argv[1]);
    
    stream = fopen(szArchivo, "r");
    printf("Filesize of MYFILE.TXT is %ld bytes\n", filesize(stream));
    printf("RecordCount of MYFILE.TXT is %ld bytes\n", RecordCount(stream));    
    fgets(szCad, 100, stream);
    printf("El primer registro del archivo es= %s\n", szCad);
    fclose(stream);
    return 0;
}
		  
long filesize(FILE *stream)
{
    long curpos, length;
		     
    curpos = ftell(stream);
    fseek(stream, 0L, SEEK_END);
    length = ftell(stream);
    fseek(stream, curpos, SEEK_SET);
    return length;
}

		  
long RecordCount(FILE *stream)
{
    long curpos, length, iTam;
    char szCad[1000];
    
    curpos = ftell(stream);
    fgets(szCad, 1000, stream);
    
    iTam= strlen(szCad);
    fseek(stream, 0L, SEEK_END);
    length = ftell(stream);
    fseek(stream, curpos, SEEK_SET);
    return length/iTam;
}
