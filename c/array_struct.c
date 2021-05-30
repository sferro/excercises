#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct str_arr {
    int num;
    char szCad[15];
};

int array(struct str_arr *);
int sum_arr(struct str_arr *);
int imp_arr(struct str_arr *);
int cargar_struct(struct str_arr *s);
int imprimir_struct(struct str_arr *s);
int Buscar(struct str_arr *, char * , int );
int Insertar(char * );


int Insertar(char *szCad) {
    static struct str_arr *ptr2;
    static int iCant = 0;
    
    if(iCant == 0) {
	ptr2 = (struct str_arr *)malloc(sizeof(struct str_arr) + 10);
	printf("paso la primer vez\n");
	array(ptr2);
	iCant = 10;
	
    }
    printf("szCad= (%s)\n", szCad);
    printf("Buscar(ptr, i, 10)= %d\n", Buscar(ptr2, szCad, iCant));
    
    return 0;
}


int Buscar(struct str_arr *arr, char *szCad, int iCant) {
    int i;
    int iResultado;
	
    iResultado = 0;
    for(i= 0; i < iCant; i++) {
        if(!strcmp(arr->szCad, szCad)) {
	    iResultado = i + 1;
	    break;
	}
	arr++;
    }
							    
    return (iResultado);
}
								

int cargar_struct(struct str_arr *s) {
    s->num = 93;
    return 0;
}

int imprimir_struct(struct str_arr *s) {
    printf("s->num= %d\n", s->num);
    return 0;
}

int array(struct str_arr *arr) {
    int i;
    
    for(i=0;i<10; i++) {
    
	arr->num= i;
	sprintf(arr->szCad, "%d", i);
	arr++;
    }

}

int sum_arr(struct str_arr *arr){
    int i;
    
    for(i=0;i<10; i++) {
	arr->num += 100;
	arr++;
    }


}


int imp_arr(struct str_arr *arr){
    int i;
    
    for(i=0;i<10; i++) {
	printf("arr->num= %d\n", arr->num);
	arr++;
    }


}

int main(void) {
    struct str_arr ptr[10],  sStruct;
    char szC[10];
    int i;
    
/*    ptr = (struct str_arr *)malloc(10 * sizeof(struct str_arr));*/
    
    array(ptr);

    imp_arr(ptr);
    
    for(i= 0; i< 5; i++) {
	sprintf(szC, "%d", i+7);
	Insertar(szC);
    }
    
    imp_arr(ptr);
    

    cargar_struct(&sStruct);
    
    imprimir_struct(&sStruct);
            
    return 0;    
}

