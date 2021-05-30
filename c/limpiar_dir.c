#include <stdio.h>
#include <stdlib.h>
	 
char *trim(char  *cadena);

int main(int argc, char **argv) {
    char *cmd = "listar.sh";
    char buf[BUFSIZ];
    char szSHELL[2048];
    char szArch[FILENAME_MAX];
    int i=0;
    FILE *ptr;

    strcpy(szSHELL, "ls -r ");
    strcat(szSHELL, argv[1]);
    if ((ptr = popen(szSHELL, "r"))!=NULL) {
	while (fgets(buf, BUFSIZ, ptr) != NULL) {
	    printf("%s", buf);
	    if(i>5) {
		strcpy(szArch, argv[1]);
		strcat(szArch, buf);
		trim(szArch);
		if(remove(szArch)!= 0)
		    printf("No se pudo borrar el archivo\n%s\n", szArch);
	    }
	    i++;
	}
	
    }
    pclose(ptr);
    trim(szArch);
    if(remove(szArch))
	printf("No se pudo borrar el archivo\n%s\n", szArch);
    else
	printf("Se pudo borrar el archivo\n%s\n", szArch);
    return 0;
}

char *trim(char  *cadena) {
    register int i;
            
    for(i = strlen(cadena)-1; i >= 0; i--)
	if(cadena[i] != ' ' && cadena[i] != '\t' && cadena[i] != '\n')
	    break;
    cadena[i+1]=0;
    return cadena;
}
				    