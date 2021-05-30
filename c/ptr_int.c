#include <stdio.h>


void main(void) {
    int *ptr, *ptr_temp;
    int i;
    ptr = (int *)malloc(10 * sizeof(int));
    
    for(i=0;i<10; i++) {
    
	*ptr= i;
	ptr++;
    }
    
    
    for(i=0; i<10; i++) {
    
	printf("ptr= %d\n", *ptr);
	ptr++;
    }
    
    
}
    