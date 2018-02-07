#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCad1[100], *szCad_Ptr1, *szCad_Ptr2;
    
    strcpy(szCad1, "Hola Mundo");
    
    szCad_Ptr1 = strdup(szCad1);
    
    printf("szCad_Ptr1 = %s\n", szCad_Ptr1);
    
    szCad_Ptr2 = szCad_Ptr1;

    printf("szCad_Ptr2 = %s\n", szCad_Ptr2);

    szCad_Ptr2 = strdup(szCad1);
        
    strcpy(szCad_Ptr1, "Hola M");

    printf("szCad_Ptr1 = %s\n", szCad_Ptr1);
    printf("szCad_Ptr2 = %s\n", szCad_Ptr2);
    
}
