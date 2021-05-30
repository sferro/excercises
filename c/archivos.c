#include <stdio.h>

int main()
	int i= 0;
	FILE *fdArch;
	
	if ((fdArch = fopen("awk/archivo.txt", "w")) = NULL) {
		printf("Error, al intentar crear el archivo\n");
		exit(1);
	}
	
	
	fprintf(fdArch, "Esto es una prueba, nro= %d\n", i);
	
	fclose(fdArch);
	
	return 0;
}
