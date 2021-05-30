/* Program 12.3 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
 
int glob = 6;
char buf[]="Para grabar en la salida estandar";

int main(int argc, char **argv)
{
    int var;
    pid_t pid= 0;
    int i;
    var = 88;
    
    printf("%s\n", buf);
    
    
    for(i=0; i < 5; i++) {    
        printf("Antes del Fork\n");
	if( (pid = fork()) < 0) {
	    printf("Error al ejecutar Fork\n");
    	    exit(1);
	}
        else if(pid == 0) {    /*Ejecucion de prceso hijo*/
    	    glob++;
    	    var++;
	}	
	else {			/*Ejecucion de proceso padre*/
	    printf("Duermo por 5 seg\n");
    	    sleep(5);
	}
    }    
    printf("pid = %d, glob= %d, var= %d\n",  getpid(), glob, var);
    printf("i= %d, ID PROC= %d, ID PADRE= %d, ID HIJO= %d\n", i, getpid(), getppid(), pid);
    exit(0);
}
