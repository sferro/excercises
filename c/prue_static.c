#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CargarArray(int *piNumeros);
int BuscarPref(int num);
int Busca(int num, int *piNum);
int ImprimirAr(int *piNum);

int BuscarPref(int num) {
  static int iFlag = 0;
  static int *piNumeros=NULL;
  int i, encontro;

  printf("Entrando a BuscarPref\n");
    
  if(!iFlag) {
	/*Cargo el array*/
	piNumeros = (int *)malloc(sizeof(int)*10);

	CargarArray(piNumeros);
	iFlag = 1;
	ImprimirAr(piNumeros);
  }

  encontro=Busca(num, piNumeros);
  if(encontro == num )
	  printf("Numero %d encontrado\n", encontro);
  else
	  printf("Numero %d No enonctrado\n", encontro);
  
  return 0;
}

int ImprimirAr(int piNum[10]) {
  int i;
  for(i=0; i<10; i++, piNum++) {
	printf("piNum[i]=%d\n", *piNum);
  }
  
  return 0;
}
int Busca(int num, int *piNum) {
  int i;

  for(i=0; i<10; i++) {
	if(*(piNum+i)==num)
	  return num;
  }
  
  return -1;
}

int CargarArray(int *piNum) {
  int i;
  printf("Entrando a CargarArray\n");
  
  
  for(i=0; i<10; i++) {
	*(piNum+i)=i;
	printf("i= %d\n", i);	
  }
  
  return 0;
}


int main(int argc, char **argv) {
  int i;
   
  for(i= 0; i< 20; i++) {
	BuscarPref(i);
  }


  return 0;
}
