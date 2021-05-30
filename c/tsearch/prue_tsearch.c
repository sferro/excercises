#include <search.h>
#include <stdlib.h>
#include <stdio.h>

void *root=NULL;

void *xmalloc(unsigned n)
{
  void *p;
  p = malloc(n);
  if(p) return p;
  fprintf(stderr, "insufficient memory\n");
  exit(1);
}

int compare(const void *pa, const void *pb)
{
  if(*(int *)pa < *(int *)pb) return -1;
  if(*(int *)pa > *(int *)pb) return 1;
  return 0;
}

void action(const void *nodep, const VISIT which, const int depth)
{
  int *datap;
  void *val;

  switch(which)
    {
    case preorder:
      break;
    case postorder:
      datap = *(int **)nodep;
      printf("%6d\n", *datap);
      break;
    case endorder:
      datap = *(int **)nodep;
      (void)tdelete(datap, &root, compare);
      free(datap);
      break;
    case leaf:
      datap = *(int **)nodep;
      printf("%6d\n", *datap);
      val = tdelete(datap, &root, compare);
      free(datap);
      break;
  }
    return;
}
					
int main()
{
    int i, *ptr;
    void *val;
		    
    for (i = 0; i < 12; i++)
    {
	ptr = (int *)xmalloc(sizeof(int));
	*ptr = rand()&0xff;
	val = tsearch((void *)ptr, &root, compare);
	if(val == NULL) exit(1);
    }
    twalk(root, action);
    return 0;
}
