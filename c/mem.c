#include <stdlib.h>

int iCalcMem( long int *tam, int incremento, long int membase )
{
  char *test;
  long int tamano= membase;
  test=malloc(tamano);
  while(!test){
     tamano -=incremento; 
     test=malloc(tamano);
  }
  /* printf("\nMaximo tamano alcanzado: %ld\n",tamano); */
  *tam = tamano;
  free(test);
  return 0;
}
