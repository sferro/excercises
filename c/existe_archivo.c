#include <stdio.h>
#include <unistd.h>

int GENExistFile(char *sPathFile);

int main(int argc, char **argv) {

    printf("%s\n", argv[1]);

    printf("%d\n", GENExistFile(argv[1]));
    
    if (GENExistFile(argv[1])==1)
	printf("existe\n");
    else
	printf("No Existe\n");
	
    return 0;
}

int GENExistFile(char *sPathFile)
{
    int iRet;
    iRet = -1;
    iRet = access(sPathFile,F_OK);
    if(iRet == 0)
	iRet = 1;
    return(iRet);
}
				
