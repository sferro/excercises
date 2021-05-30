#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct estructura {
  int num;
  char szCad[10];
};


int InicEstructura(struct estructura *a) {
  a->num = 0;
  a->szCad[0] = '\0'; 

  return 0;
}

int CopiarEstruct(struct estructura *a, struct estructura *b) {
  a->num = b->num;
  strcpy(a->szCad, b->szCad);

  return 0;
}

int main(int argc, char **argv) {
  struct estructura sA, sB;
  
  InicEstructura(&sA);

  sA.num = 5;
  strcpy(sA.szCad, "Seba");
  
  CopiarEstruct(&sB, &sA);
  
  printf("%s= %d\n%s= %s\n", 
		  "Num", sB.num,
		  "szCad", sB.szCad);
		  

  
  return 0;
}