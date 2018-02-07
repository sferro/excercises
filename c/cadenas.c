#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char cad1[50], cad2[50], cad3[50];
	
	strcpy(cad1, argv[1]);
	sprintf(cad2, ":%-20s:", argv[2]);
	
	*cad3= '\0';
	
	if(!cad3) 
		printf("cad3 es nulo\n");
	else
		printf("cad3 no es nulo\n");
	
	printf("%s %s\n", cad1, cad2);
	
	return 0;
}
