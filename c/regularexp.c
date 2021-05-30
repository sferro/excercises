#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
  char ret0[20];
  char *newcursor, *name;
  char szCadena[100];
  
  if(argc < 2) {
	printf("No ingreso cadena\n");
	exit(1);
  }
  strcpy(szCadena, argv[1]);
  				
/*  name = regcmp("SEBA\\.[0-9][0-9][0-9][0-9][0-9]\\.TXT", (char *)0);*/
  name = regcmp("([SEBA\\.[0-9]{0,5}\\.[A-za-z0-9]{0,7}\\.TXT)", (char *)0);

  if( (newcursor = regex(name, szCadena, ret0)) == NULL ) {
	printf("Error en Regexpr\n");
	exit(1);
  }
	
  printf("name= <%s>\n", name);
  printf("newcursor= <%s>\n", newcursor);
  printf("ret0= <%s>\n", ret0);

  return 0;
}
  