#include <stdio.h>

int main(int argc, char **argv) {
    int num, i;
    
    for(i=0; i<40; i++) {
	num = i;
	num = num % 10;
	printf("%d mod 10 = %d\n", i, num);
    }
    
    return 0;
}