#include <stdio.h>

int main(int argc, char **argv) {
    int iRet;
    
    iRet= 999;
    
    iRet=system("find / -name moroaestudio.pc");
    printf("iRet= %d\n", iRet);
    
    return 0;
}