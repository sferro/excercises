#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCad1[100], szCad2[100];
    
    sprintf(szCad1, "%s%d\n", "cadena", 1);
    
    printf("szCad1= %s%s\n", szCad1, "probando");

    strcpy(szCad2, szCad1);
    strcat(szCad2, "------");
    strcat(szCad2, "\n");
    
    printf("szCad2= %s%s\n", szCad2, "fin");
    
    return 0;
    
}
