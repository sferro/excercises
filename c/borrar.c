#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pp {
    char szCad2[100];
};

int main(int argc, char **argv) {
    char szCad1[100];
    char szCad2[100];
    struct pp ppp;
    struct pp *pppp;
    
    pppp = malloc(sizeof(struct pp *));
    
    strcpy(szCad1, "0123456789");
    
    printf("szCad1= (%s)\n", szCad1);
    
    strcpy(szCad1, &szCad1[1]);
        
    printf("szCad1= (%s)\n", szCad1);
    
    strcpy(ppp.szCad2, "0123456789");
    
    printf("ppp.szCad2= (%s)\n", ppp.szCad2);
    
    strcpy(ppp.szCad2, &ppp.szCad2[1]);
    

    printf("ppp.szCad2= (%s)\n", ppp.szCad2);
    
    strcpy(pppp->szCad2, "0123456789");
    
    printf("pppp->szCad2= (%s)\n", pppp->szCad2);
    
    strcpy(pppp->szCad2, &pppp->szCad2[1]);
    

    printf("pppp->szCad2= (%s)\n", pppp->szCad2);

    strcpy(szCad1, "0123456789abcdefghijklmnopqrstuvwxyz");
    
    printf("szCad1= (%s)\n", szCad1);
    
    strcpy(&szCad1[10], "esto es una prueba");

    printf("szCad1= (%s)\n", szCad1);
    
    return 0;
}