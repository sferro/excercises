#include <stdio.h>

int funcion1(int *a);
int funcion2(int *a);


int funcion1(int *a) {
    int n;
    
    n = *a;

    *a= 20;
    
    funcion2(a);
    
    return n;
}

int funcion2(int *a) {
    int n;
    
    n = *a;
    
    *a = 30;
    
    return n;
}

int main(int argc, char **argv) {
    int num= 10;

    
    printf("funcion1 = %d\n", funcion1(&num));

    printf("num= %d\n", num);    
    

    return 0;
    
}
    