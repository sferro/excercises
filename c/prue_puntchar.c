#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int func1(char **c);
int func2(char **c);

int func1(char **c) 
{
    printf("func1 c = %p\n", c);
    printf("func1 *c = %p\n", *c);
	
	*c = (char *)malloc(sizeof(char) * 10);

    printf("func1 c = %p\n", c);
    printf("func1 *c = %p\n", *c);
	
	strcpy(*c, "func1");
  
	return 0;
}

int func2(char **c) 
{
    printf("func2 c = %p\n", c);
    printf("func2 *c = %p\n", *c);
	
	free(*c);

    printf("func2 c = %p\n", c);
    printf("func2 *c = %p\n", *c);
	
  
	return 0;
}

int main(int argc, char **argv) {
    char *szCad;

    printf("Sin inic: &szCad = %p\n", szCad);
	
	szCad = NULL;
	printf("Inic a null &szCad = %p\n", szCad);
	
	szCad = (char *)malloc(sizeof(char) * 100);
    printf("Despues malloc &szCad = %p\n", szCad);
	
	free(szCad);
    printf("Despues free &szCad = %p\n", szCad);

	szCad = 0;
    printf("Inic 0 &szCad = %p\n", szCad);

	func1(&szCad);
    printf("func1 &szCad = %p\n", szCad);
    printf("func1 &szCad = %s\n", szCad);
	
	func2(&szCad);
    printf("func2 &szCad = %p\n", szCad);
    printf("func2 &szCad = %s\n", szCad);
	
    return 0;
    
}
