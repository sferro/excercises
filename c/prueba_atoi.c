#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char szCad[100];
    char szNum[5];
    int iNum;
    
    memset(szNum, 0, 5);
    
    strcpy(szCad, "0123456789012345678901234567890");
    
    iNum = atoi(strncpy(szNum, &szCad[10], 4));
    
    printf("iNum = %d\n", iNum);
}
