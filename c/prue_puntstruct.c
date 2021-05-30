#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct s {
  char *c;
};

int func1(struct s *);


int func1(struct s *ps)
{
	ps->c = (char *)malloc(sizeof(char) * 10);	
	strcpy(ps->c, "func1");
  
	return 0;
}

int main(int argc, char **argv) 
{
    struct s stru;

	func1(&stru);
    printf("func1 stru.c = %s\n", stru.c);
	
    return 0;
}
