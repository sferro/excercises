#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buf[100];
    
    sprintf(buf,"%s %d", "El resultado es= ", 5);
    
    printf("\n%s\n", buf);


    sprintf(buf,"%s %-05d", "El res= ", 5);
    
    printf("\n%s\n", buf);

    sprintf(buf,"%s %d", "El resultado es= ", 125);
    
    printf("\n%s\n", buf);

    sprintf(buf,"%-020s%05s%-10s% -12s% 5s%s", "20", "5", "10", "12", "5", "1");
    
    printf("\n%s\n", buf);

    return 0;
    
    
}