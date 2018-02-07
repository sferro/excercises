#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) 
{
  FILE *pfd;
  char szLinea[1024];
  
  while(1) {

    if((pfd = fopen("borrar_fifo", "r")) == NULL) {
  	  printf("No se pudo abrir archivo fifo\n");
  	  exit(1);
	}
  
	while(!feof(pfd)) {
  
	  if(fgets(szLinea, 1024, pfd))
		printf("szLinea= (%s)\n", szLinea);
	
	}

    fclose(pfd);

	if(!strncmp(szLinea, "FIN", 3)) break;
  
  }
  return 0;
}
