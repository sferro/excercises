#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int main(int argc, char **argv) {
    char szCad1[TAM], szCad2[TAM];
    
        
    strcpy(szCad1, "0123456789abcdefghijklmnopqrstuvwxyz");

    printf("szCad1= (%s)\n", szCad1);
        
    memcpy(szCad2, &szCad1[4], 5); szCad2[5] = 0;
    
    printf("&szCad1[4], 5= (%s)\n", szCad2);
    
    strncpy(szCad2, &szCad1[8], 4); szCad2[4] = 0;
    
    printf("&szCad1[8], 4= (%s)\n", szCad2);

    return 0;

}
