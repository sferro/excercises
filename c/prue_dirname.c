#include <stdio.h>
#include <libgen.h>

int main() {

  char *dirc, *basec, *bname, *dname;
  char *path = "strc";
			  
  dirc = strdup(path);
  basec = strdup(path);
  dname = dirname(dirc);
  bname = basename(basec);
  printf("dirname=%s, basename=%s\n", dname, bname);
  free(dirc);
  free(basec);
}															   