#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char cad[100];
	char filename[50];
	FILE *fp;
	
	if (argc < 2) {
		printf("\nDebe ingresar como parametro el nombre del archivo:\n");
		exit(1);
	}
	strcpy(filename, argv[1]);
	
	if((fp=fopen(filename, "r"))==NULL) {
		printf("\nNo se pudo abrir el archivo %s\n", filename);
		exit(1);
	}
/*	
	do {
		printf("Introduzca una cadena, INTRO para finalizar:\n");
		gets(cad);

		strcat(cad, "\n");
		fputs(cad, fp);

	}while (*cad!='\n');*//* while(strcmp(cad, "fin"));*/
	/*
	rewind(fp);
*/	
	while(!feof(fp)) {
		fgets(cad, 99, fp);
		if (*cad!='\n')
			printf(cad);
		strcpy(cad,"\n");
	}

/*	do {
		fgets(cad, 99, fp);
		printf(cad);
	} while(!feof(fp)); 
*/	
	return 0;
}
