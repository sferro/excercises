#include <stdio.h>
#include <stdlib.h>

#define NUM 0.930000
int main(int argc, char **argv) {
    double dNum;
    int iNum;
    int lNum;
    
    dNum = 930.00000;
    
    iNum = (int)dNum;
    lNum = (long int)dNum; 
    
    
    printf("dNum %f\n", dNum);
    printf("iNum %d\n", iNum);
    printf("lNum %d\n", lNum);
    
    
    return 0;
}
    