#include <stdio.h>
#include <string.h>

/*
Valores posibles para el formato
pueden venir en Minusculas o Mayusculas
Y  = anio
M  = mes
D  = dia
H  = Hora
m  = Minutos
S  = segundo
*/

int ValidarFecha(char *szFecha, char *szFomato)
{
    int iLenFecha, iLenFormato;
    
    iLenFecha = strlen(szFecha);
    iLenFormato = strlen(szFormato);
    
    if(iLenFecha != iLenFormato) 
	return 1;

    
    
    return 0;
}

int main(int argc, char *argv[]) {
    


    return 0;
}
