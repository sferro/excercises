#include <stdio.h>
#include <errno.h>
#include <string.h>

int main ()
{
    printf("El char es de       :%d Bytes\n",sizeof(char));
    printf("El short es de      :%d Bytes\n",sizeof(short));
    printf("El short int es de  :%d Bytes\n",sizeof(short int));
    printf("El unsigned int es  :%d Bytes\n",sizeof(unsigned int));
    printf("El int es de        :%d Bytes\n",sizeof(int));
    printf("El long es de       :%d Bytes\n",sizeof(long));
    printf("El long int es de   :%d Bytes\n",sizeof(long int));
    printf("El long long es de  :%d Bytes\n",sizeof(long long));
    printf("El float es de      :%d Bytes\n",sizeof(float));
    printf("El double es de     :%d Bytes\n",sizeof(double));
    printf("El long double es de:%d Bytes\n",sizeof(long double));
    printf("El size_t es de     :%d Bytes\n",sizeof(size_t));
    

    return(0);		
}
