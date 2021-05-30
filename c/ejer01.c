/************************************************************************
		TPN 2
		Ejercicio: 2
		Alumno:  FERRO, Sebastian	LEG: 42247
				 BALBO, Mario		LEG: 41050
				 CARINO, Cesar		LEG: 38669-1
		CURSO: 	 1K9
************************************************************************/

#include <stdio.h>
#include <string.h>

void cargar_matriz(int [31][10]);
void mostrar_matriz( int [31][10]);
void cargar_precio(float [31]);
void cargar_nombre(char [10][50]);
void cargar_marca(char [31][50]);

void cargar_matriz(int m[31][10]) {
	register int i, j;
	int cantidad;
	
	for(i=0;i<31;i++) {
		for(j=0;j<10;j++) {
			printf("Ingrese la cantidad vendida del automovil %d por el vendedor %d\n",i,j);
			scanf("%d", &cantidad);
			m[i][j]=cantidad;
		}
	}
}

void mostrar_matriz(int m[31][10]) {
	register int i, j;
	
	for(i=0;i<31;i++) {
		for(j=0;j<10;j++)
			printf("Vendedor %d, Auto %d = %d\n", j,i,m[i][j]);
	}
}
	
void cargar_precio(float p[31]) {
	register int i;
	float precio;
	
	for(i=0;i<31;i++) {
		printf("Ingrese precio para auto %d\n", i);
		scanf("%f", &precio);
		p[i]=precio;
	}
}

void cargar_nombre(char n[10][50]) {
	register int i;
	char nombre[50];
	for(i=0;i<10;i++) {
		printf("Ingrese Nombre de vendedor %d\n", i);
		gets(nombre);
		strcpy(n[i], nombre);
	}
}

void cargar_marca(char n[31][50]) {
	register int i;
	char nombre[50];
	for(i=0;i<31;i++) {
		printf("Ingrese marca %d\n", i);
		gets(nombre);
		strcpy(n[i], nombre);
	}
}
	
int main() {
	register int i, j;
	char nombres[10][50], marcas[31][50];
	int mat[31][10];
	float precios[31], importe_tot, importe_tot_vend;
	
	importe_tot=importe_tot_vend=0;
	
	printf("Ingrese lo autos vendidos por vendedor\n");
	cargar_matriz(mat);
	
	printf("Ingrese el precio de cada vehiculo\n");
	cargar_precio(precios);
	
	printf("Ingrese los nombre de los vendedores\n");
	cargar_nombre(nombres);
	
	printf("Ingrese las marcas de los vehiculos\n");
	cargar_marca(marcas);

	for(i=0;i<31;i++) {
		printf("%s:\t", marcas[i]);
		for(j=0;j<10;j++) {
			importe_tot += (mat[i][j]*precios[i]);
		}
		printf("%.2f\n", importe_tot);
	}
	
	for(i=0;i<10;i++) {
		printf("%s\t", nombres[i]);
		for(j=0;j<31;j++) {
			importe_tot_vend+=(mat[j][i]*precios[j]);
		}
		printf("%.2f\t", importe_tot_vend);
		printf("Promedio= %.2f\n",importe_tot_vend/10); 
	}
	
	return 0;
}