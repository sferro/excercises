#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int irand;
    register int i;
    int cont1,f1, 
	cont2,f2, 
	cont3,f3, 
	cont4,f4, 
	cont5,f5, 
	cont6,f6, 
	cont7,f7, 
	cont8,f8,
	cont9,f9, 
	cont10,f10, 
	cont11,f11;

    int imod;
    
    cont1 = cont2 = cont3 = cont4 = cont5 = cont6 = cont7 = cont8 = cont9 = cont10 = cont11 = 0;
    
    f11=f10=f9=f8=f7=f6=f5=f4=f3=f2=f1=0;

    printf("randmax = %d\n", RAND_MAX);

    for(i=0; i<100; i++) {
	  irand = rand();
	
	  printf("irand = %ld\n", rand());
    }
    
    for(i=0;i<30000;i++) {
	irand = rand();
	
	imod = irand % 2;
	if(imod == 0) {
	    f8=f7=f6=f5=f4=f3=f2=f1=f9=f10=f11=0;
	}
	else {
	    f8++;f7++;f6++;f5++;f4++;f3++;f2++;f1++;f9++;f10++;f11++;
	}
	if (f8==8)
	    cont8++;
	if (f7==7)
	    cont7++;
	if (f6==6)
	    cont6++;
	if (f5==5)
	    cont5++;
	if (f4==4)
	    cont4++;
	if (f3==3)
	    cont3++;
	if (f2==2)
	    cont2++;
	if (f1==1)
	    cont1++;
	if (f9==9)
	    cont9++;
	if (f10==10)
	    cont10++;
	if (f11==11)
	    cont11++;
	    
    }
    printf("porcentaje 1= %d\n", cont1);
    printf("porcentaje 2= %d\n", cont2);
    printf("porcentaje 3= %d\n", cont3);
    printf("porcentaje 4= %d\n", cont4);
    printf("porcentaje 5= %d\n", cont5);
    printf("porcentaje 6= %d\n", cont6);
    printf("porcentaje 7= %d\n", cont7);
    printf("porcentaje 8= %d\n", cont8);
    printf("porcentaje 9= %d\n", cont9);
    printf("porcentaje 10= %d\n", cont10);
    printf("porcentaje 11= %d\n", cont11);
    return 0;
}
