#include <stdio.h>

int main(int argc, char **argv) {


    int n;
    
    n = (1 == 1 ? 23 : 2);
    
    printf("n= %d\n", n);
    
    n = (1 == 2 ? 3 : 24);
    printf("n= %d\n", n);
    
    return 0;
    
}

     