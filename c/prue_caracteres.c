#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int strlen_esp(const char *);

int strlen_esp(const char *s) {
  const char *temp = s;
  
  while(*temp++ != 3);

  return temp - s - 1;	
  
}

int main(int argc, char **argv) 
{
  char szCad[100];
  
  strcpy(szCad, "0123456789");
  printf("szCad = (%s)\n", szCad);
  printf("strlen = (%d)\n", strlen(szCad));


  szCad[3] = 3;
    
  printf("szCad = (%s)\n", szCad);
  printf("Pos car 3 = (%d)\n", strlen_esp(szCad));
  
  strcpy(szCad, "0123456789");
  szCad[6] = 3;
    
  printf("szCad = (%s)\n", szCad);
  printf("Pos car 3 = (%d)\n", strlen_esp(szCad));
  
  
  return 0;
}

