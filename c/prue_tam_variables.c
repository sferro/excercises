#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int iEntero;
  char szChar;
  long int liLong;
  long long llLong;
  float fFloat;
  double dDouble;
  long double ldDouble;
  
  printf("iEntero = %d\n", sizeof(iEntero));
  printf("szChar = %d\n", sizeof(szChar));
  printf("liLong = %d\n", sizeof(liLong));
  printf("llLong = %d\n", sizeof(llLong));
  printf("fFloat = %d\n", sizeof(fFloat));
  printf("dDouble = %d\n", sizeof(dDouble));
  printf("ldDouble = %d\n", sizeof(ldDouble));
      
  return 0;
    
}
