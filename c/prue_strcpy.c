#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCad1[100];
    char szCad2[100];
    
    strcpy(szCad1, "cadena1.tmp");
    strcpy(szCad2, "cadena2.ok");
    
    printf("szCad1= (%s)\n", szCad1);
    printf("szCad2= (%s)\n", szCad2);
    
    strcpy(&szCad1[8], "T");
    strcpy(&szCad2[8], "O");
    
    printf("strcpy(&szCad1[8], 'T');= (%s)\n", szCad1);
    printf("strcpy(&szCad2[8], 'O');= (%s)\n", szCad2);
    
    
    return 0;
    
}
