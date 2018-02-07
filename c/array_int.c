#include <stdio.h>

int inic_arr(int *arr)
{
    int i;
    for(i=0;i<10;i++) {
	arr[i] = 0;
    }
}

int print_arr(int *arr)
{
    int i;
    for(i=0;i<10;i++) {
	printf("arr[%d]= %d\n", i, arr[i]);
    }
}

int llenar_arr(int *arr)
{
    int i;
    for(i=0;i<10;i++) {
	arr[i] = i;
    }
}


int main(int argc, char **argv)
{
    int array_int[10];
    int *int_ptr;

    printf("Inicializando array estatico\n");    
    inic_arr(array_int);
    
    print_arr(array_int);
    
    llenar_arr(array_int);
    
    print_arr(array_int);
    
    printf("Inicializando array dinamico\n");
    int_ptr = (int *)malloc(10 * sizeof(int));
    
    inic_arr(int_ptr);
    
    print_arr(int_ptr);
    
    llenar_arr(int_ptr);
    
    print_arr(int_ptr);
    
    return 0;

}
