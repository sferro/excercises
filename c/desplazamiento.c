#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    int iNum;
    float fNum;
    
    for(iNum=-50; iNum<100; iNum++) {
	printf("iNum= (%d), iNum(>>) = (%d)\n", iNum , iNum>>1);
    }
    
    return 0;
    
}
