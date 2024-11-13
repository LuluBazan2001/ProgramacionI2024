/*Escribe un programa para encontrar la suma de la serie 1+11+111+1111+...n. El
usuario debe determinar un valor donde n es menor a dicho valor.*/

#include<stdio.h>

int main() {
	float acum;
	float i;
	float n;
	float x;
	float z;
	printf("Ingrese un valor: \n");
	scanf("%f",&x);
	acum = 0;
	z = 0;
	n = 0;
	while (n<x) {
		z = n;
		n = 1+(n*10);
		acum = acum+z;
	}
	printf("La sumatoria de serie es: %f\n",acum);
	printf("Numero mas cercano es: %f\n",z);
	return 0;
}

