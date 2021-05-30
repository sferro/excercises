#include <search.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct s {
    char szLeg[10];
    char szValor[10];
};

void *root=NULL;

void *xmalloc(unsigned n)
{
  struct s *p;
  p = (struct s *)malloc(n);
  if(p) return p;
  fprintf(stderr, "insufficient memory\n");
  exit(1);
}

int compare(const void *pa, const void *pb)
{
    return(strcmp(pa->szLeg, pb->szLeg));
}

void action(const struct s *nodep, const VISIT which, const int depth)
{
  struct s *datap;
  void *val;

  switch(which)
    {
    case preorder:
      break;
    case postorder:
      datap = *(struct s **)nodep;
      printf("(%s) - (%s)\n", datap->szLeg, datap->szValor);
      break;
    case endorder:
      datap = *(struct s **)nodep;
      (void)tdelete(datap, &root, compare);
      free(datap);
      break;
    case leaf:
      datap = *(struct s **)nodep;
      printf("(%s) - (%s)\n", datap->szLeg, datap->szValor);
      val = tdelete(datap, &root, compare);
      free(datap);
      break;
  }
    return;
}
					
int main()
{
    void *val;
    struct s *sp;
    char szLeg[10];
    char szValor[10];
    
    
    printf("tipee (salir) para finalizar\n");
    szLeg[0]=0;
    while(1)
    {
	printf("szLeg="); scanf("%s\n", szLeg);
	if(!strcmp(szLeg, "salir")) break;
	printf("szValor="); scanf("%s\n", szValor);
	
	sp = (struct s*)xmalloc(sizeof (struct s));
	strcpy(sp->szLeg, szLeg);
	strcpy(sp->szValor, szValor);
	
	val = tsearch((void *)sp, &root, compare);
	if(val == NULL) {
	    printf("Error en la busqueda\n");
	    exit(1);
	}
	printf("val= %p\n", val);
	
    }
    twalk(root, action);
    return 0;
    
}
