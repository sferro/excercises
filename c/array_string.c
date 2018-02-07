#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int array(char **arr_str);
int sum_arr(char **arr_str);
int imp_arr(char **arr_str);

int array(char **arr_str) {
    int i;
    char szTemp[10];
    
    for(i=0;i<10; i++) {
	memset(szTemp, 0, 10);
	arr_str[i] = (char *)malloc(100 * sizeof(char));
	strcpy(arr_str[i], "hola ");
	sprintf(szTemp, "%d", i);
	strcat(arr_str[i], szTemp);
    }
}

int sum_arr(char **arr_str){
    int i;
    char szTemp[10];
    
    for(i=0;i<10; i++) {
	memset(szTemp, 0, 10);
	arr_str[i] = (char *)malloc(100 * sizeof(char));
	strcpy(arr_str[i], "Seba ");
	sprintf(szTemp, "%d", i + 100);
	strcat(arr_str[i], szTemp);
    }
}


int imp_arr(char **arr_str){
    int i;
    
    for(i=0;i<10; i++) {
	printf("arr= %s\n", arr_str[i]);
    }
}

int main(int argc, char **argv) {
    char **ptr;
    int i;
    ptr = (char **)malloc(10 * sizeof(char *));
    
    array(ptr);
    
    imp_arr(ptr);
    
    sum_arr(ptr);
    
    imp_arr(ptr);
    
}
