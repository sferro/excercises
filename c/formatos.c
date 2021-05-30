#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    
    printf("Parametros= %d\n", argc);
    
    
    printf("%-24s+54%-15s\n", argv[1], argv[2]);			/* COMPLETO */
    printf("%-24s+%-17s\n", argv[1], argv[2]);				/* INTERNACIONAL */
    printf("%-24s%-18s\n", argv[1], "*");				/* TODOS LOS ORIGENES */
    
    return 0;
    
}