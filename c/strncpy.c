#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char *strPtr;
	char cadena[150];
	char letra[2];
	
	strPtr = (char *)malloc(100);
	
	strcpy(strPtr, "123456789|abcdefghijklmnopqrstuvwxyz");
	
	strncpy(cadena, &strPtr[9], 5);
	
	cadena[5]='\0';
	
	printf("cadena= %s\n", cadena);
	
	
	strcpy(letra,"a");
	
	strcpy(cadena, letra);
	
	printf("cadena= %s\n", cadena);
	
	return 0;
}
