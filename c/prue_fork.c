/* Program 12.3 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
 
 
void main(int argc, char *argv[])
{
    int child, i, a;
    FILE *pfdArch;
    
    if( (pfdArch= fopen("archivo_fork.txt", "w"))==NULL) {
	printf("Error al abiri el archivo\n");
	exit(1);
    
    }
    i=0;
    a=1;
    for(i= 0; i< 10; i++) {     
 
        if ((child = fork()) == -1) {
	    fprintf(stderr, "Could not fork a child\n");
	    break;
        }  
 
	if (child == 0) {   /* child code */
	    fprintf(stdout, "Generacion hijo %d\n", i);
	    a=a*3;	/*paa mostrar que a es igual en todos los proceso y no se incrementa*/
	    fprintf(stdout, "a= %d\n", a);
	    
	    sleep(i * 5);  
	    fprintf(stdout, "Generacion hijo %d\n", i);
	    exit(0);
 
	}
	else {                                    /* parent code */
	    fprintf(stdout, "i = %d child = %d\n",i,  child);
	    while (waitpid(-1, NULL, WNOHANG) > 0)
        	;
	    fprintf(stdout, "i = %d child = %d\n",i,  child);
	}   
    }
   
    exit(0);
}
