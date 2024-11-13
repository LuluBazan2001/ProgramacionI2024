/*. Realizar un programa que permita determinar a cuantas semanas equivale un numero
ingresado que está expresado en minutos. Considere el ingreso de 15 números.*/

#include<stdio.h>

main(){
	int minutos,repeticion;
	float semanas;
	float minutossemanas=10080;
	
	for (repeticion=0;repeticion<=15;repeticion+=1)
	{
		printf("Ingrese el numero que desea pasar de minutos a semanas\n");
		scanf("%d",&minutos);
		semanas=minutos/minutossemanas;
		printf("La cantidad de semanas es:%f\n",semanas);
	}
	
	return 0;
}
