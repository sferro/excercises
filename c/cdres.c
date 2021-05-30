#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char sz19[2], sz20[2], sz43[2], sz44[2];
	
	strcpy(sz19, argv[1]);
	strcpy(sz20, argv[2]);
	strcpy(sz43, argv[3]);
	strcpy(sz44, argv[4]);
	
	if(!strcmp(sz19, "U") && !strcmp(sz20, "U") && !strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 0");
	else if(!strcmp(sz19, "U") && !strcmp(sz20, "U") && !strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 1");
	else if(!strcmp(sz19, "U") && !strcmp(sz20, "U") && strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 2");
	else if(!strcmp(sz19, "U") && !strcmp(sz20, "U") && strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 3");
	else if(!strcmp(sz19, "U") && strcmp(sz20, "U") && !strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 4");
	else if(!strcmp(sz19, "U") && strcmp(sz20, "U") && !strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 5");
	else if(!strcmp(sz19, "U") && strcmp(sz20, "U") && strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 6");
	else if(!strcmp(sz19, "U") && strcmp(sz20, "U") && strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 7");
	else if(strcmp(sz19, "U") && !strcmp(sz20, "U") && !strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 8");
	else if(strcmp(sz19, "U") && !strcmp(sz20, "U") && !strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 9");
	else if(strcmp(sz19, "U") && !strcmp(sz20, "U") && strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 10");
	else if(strcmp(sz19, "U") && !strcmp(sz20, "U") && strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 11");
	else if(strcmp(sz19, "U") && strcmp(sz20, "U") && !strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 12");
	else if(strcmp(sz19, "U") && strcmp(sz20, "U") && !strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 13");
	else if(strcmp(sz19, "U") && strcmp(sz20, "U") && strcmp(sz43, "U") && !strcmp(sz44, "U"))
		printf("valor= 14");
	else if(strcmp(sz19, "U") && strcmp(sz20, "U") && strcmp(sz43, "U") && strcmp(sz44, "U"))
		printf("valor= 15");
	
	
	return 0;
}
