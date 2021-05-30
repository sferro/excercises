#include <stdio.h>

int main(int argc, char **argv) {
    int a,b,i;
    
    for(i=0;i<10;i++) {
        printf("a y b= ");
        scanf("%d%d\n", &a, &b);
    
        printf("%d&%d= %d\n",a, b , a&b);
        printf("%d|%d= %d\n",a, b,  a|b);
    }	
    return 0;
}
