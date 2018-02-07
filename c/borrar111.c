#include <stdio.h>

int funcion(int *ptr)
{
    printf("ptr = %p\n", ptr);
    printf("ptr = %d\n", *ptr);
}
    

int funcion2(int *ptr)
{
    int i;
    printf("Empezo func2\n");    
    for(i= 0; i<9;i++) {
        *ptr = i;

	printf("ptr = %p\n", ptr);
        printf("ptr = %d\n", *ptr);

        ptr++;

    }
    printf("Fin func2\n");

}

int main(int argc, char **argv) {
    int *ptr_iNum, *ptr_iNum2;
    int iNum;
    
    ptr_iNum = NULL;
    iNum=5;
    ptr_iNum = &iNum;
    
    printf("ptr_iNum = %p\n", ptr_iNum);

    printf("ptr_iNum = %d\n", *ptr_iNum);
    
    funcion(ptr_iNum);
    
    printf("ptr_iNum = %p\n", ptr_iNum);


    ptr_iNum2=NULL;    

    ptr_iNum2 = (int *)malloc(sizeof(int)*10);
    printf("ptr_iNum 2= %p\n", ptr_iNum2);
    printf("ptr = %p\n", ptr_iNum2);
    printf("ptr = %d\n", *ptr_iNum2);

    funcion2(ptr_iNum2);
    
    printf("ptr = %p\n", ptr_iNum2);
    printf("ptr = %d\n", *ptr_iNum2);
    
    return 0;

}
