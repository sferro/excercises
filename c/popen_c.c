#include <stdio.h>
#include <stdlib.h>
	 
int main(int argc, char **argv) {
    char cmd[10];
    char buf[BUFSIZ];
    char szSHELL[2048];
    FILE *ptr;

    if(argc != 3) {
	printf("Se han ingresado mal los parametros\n");
	exit(1);
    }
    
    strcpy(cmd, argv[1]);
    
    
    strcpy(szSHELL, cmd);
    strcat(szSHELL, " ");
    strcat(szSHELL, argv[2]);
    if ((ptr = popen(szSHELL, "r"))!=NULL) {
	while (fgets(buf, BUFSIZ, ptr) != NULL)
	    printf("%s", buf);
    }
    pclose(ptr);
    return 0;
}
