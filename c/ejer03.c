/************************************************************************
		TPN 2
		Ejercicio: 3
		Alumno:  FERRO, Sebastian	LEG: 42247
				 BALBO, Mario		LEG: 41050
				 CARINO, Cesar		LEG: 38669-1
		CURSO: 	 1K9
************************************************************************/
#include <stdio.h>

struct envio {
	int movil;
	int destino;
	float importe;
	char carga;
};

void cargar_vector(struct envio [100]);
float importe(struct envio [100]);
int envios_tipo(struct envio [100], char);
int envios_movil(struct envio [100], int);

float importe(struct envio v[100]) {
	register int i;
	float total;
	total=0;
	
	for(i=0;i<100;i++) 
		total += v[i].importe;
	return total;
}

int envios_tipo(struct envio v[100], char c) {
	register int i;
	int total;
	total=0;
	
	for(i=0;i<100;i++) {
		if(v[i].carga==c)
			total++;
	}
	return total;
}	

int envios_movil(struct envio v[100], int n) {
	register int i;
	int total;
	total=0;
	
	for(i=0;i<100;i++) {
		if(v[i].carga==n)
			total++;
	}
	return total;
}	
	
void cargar_vector(struct envio v[100]) {
	register int i;
	int m, d;
	char c;
	float f;
	for(i=0;i<100;i++) {
		printf("Ingrese Num de movil ");
		scanf("%d", &m);
		v[i].movil=m;
		printf("Ingrese destino ");
		scanf("%d", &d);
		v[i].destino=d;
		printf("Ingrese importe ");
		scanf("%f", &f);
		v[i].importe=f;
		printf("Ingrese carga ");
		scanf("%c", &c);
		v[i].carga=c;
	}
}


void main() {
	register int i;
	struct envio vector[100];
	float importe_tot, importe_tot5, porcentaje;
	char tipo_carga[]={'a','b','c'};
	int cargas[3], total_envios;
	char ucarga;
	
	printf("Cargar vector de estructura\n");
	cargar_vector(vector);
	printf("El Importe total de todo los envios es: ");
	importe_tot=importe(vector);
	
	for(i=0;i<3;i++) {
		ucarga=tipo_carga[i];
		cargas[i]=envios_tipo(vector, ucarga);
		porcentaje=cargas[i]/100;
		printf("Para la carga %c, el porcentaje es %.2f", ucarga, porcentaje);
	}
	
	importe_tot5=0;
	for(i=0;i<100;i++) {
		if(vector[i].destino==5)
			importe_tot5 += vector[i].importe;
	}
	printf("El Importe para el destino 5 es %.2f\n", importe_tot5);
	
	for(i=0;i<10;i++) {
		total_envios=envios_movil(vector, i);
		printf("Movil %d hizo %d envios\n", i, total_envios);
	}
}